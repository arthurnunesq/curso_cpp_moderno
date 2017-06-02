std::queue<int> q;
std::atomic<bool> done(false);

void reader()
{
    // ...
    q.push(10);
    done = true;
}