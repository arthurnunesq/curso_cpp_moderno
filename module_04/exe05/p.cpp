constexpr unsigned long long int factorial(unsigned long long int x){
    return  x > 1 ? x*factorial(x-1) : 1;
}

int main(){
    unsigned long long int i = 0;
    switch (i){
    case -1: break;
    case factorial(1): break;
    case factorial(2): break;
    case factorial(10): break;
    case factorial(521): break;
    case factorial(522): break;
    }
    return 0;
}
