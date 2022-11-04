#include <iostream>

int factorial(int n)
{
    int factorial = 1;
    for (int i = 1; i < n + 1; i++)
    {
        factorial *= i;
    }
    return factorial;
}

long int rec_fact(long int n)
{
    if (n > 1)
    {
        return n * rec_fact(n - 1);
    }
    else
    {
        return 1;
    }
}

int hello(){
    
}

int main()
{
    std::cout << "Fact: " << rec_fact(1000000) << std::endl;
}