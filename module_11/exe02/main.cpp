#include <iostream>
#include <vector>
#include <deque>

#include <algorithm>
#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <mutex>

#include <signal.h> 

volatile sig_atomic_t continue_flag = 1;
void termination_handler(int sig){ // can be called asynchronously
    continue_flag = 0; // set flag
    std::cout << "Termination requested." << std::endl;
}

std::deque<std::packaged_task<void()>> message_queue;
std::mutex m;

float randf(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

void post(){
    int i = 0;
    while(continue_flag){
        std::packaged_task<void()> task( [i] () { 
            auto duration = std::chrono::duration<double>(randf(0.5, 5.0));
            std::cout << "Id " << i << ": sleeping for " << duration.count() << std::endl;
            std::this_thread::sleep_for(duration);
            std::cout << "Id: " << i << std::endl;
        });

        {
            std::lock_guard<std::mutex> lock(m);
            std::cout << "Adding message..." << std::endl;
            message_queue.push_back(std::move(task));
        }

        i++;

        std::cout << "Post sleeping..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Post woke!" << std::endl;
    }
}

void proccess(){
    int i = 0;
    while(continue_flag){
        {
            std::lock_guard<std::mutex> lock(m);
            if(!message_queue.empty()){
                std::cout << "Processing message..." << std::endl;
                auto& task = message_queue.front();
                auto future = task.get_future();
                task(); // This blocks!!!
                        // https://stackoverflow.com/questions/18143661/what-is-the-difference-between-packaged-task-and-async
                message_queue.pop_front();
                std::cout << "Processed message!" << std::endl;
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        
    }
}

int main()
{
    // Register signals 
    signal(SIGINT, termination_handler); 
    signal(SIGTERM, termination_handler);

    // post();
    std::thread t1(&post);
    std::thread t2(&proccess);
    t1.join();
    t2.join();


    return 0;
}
