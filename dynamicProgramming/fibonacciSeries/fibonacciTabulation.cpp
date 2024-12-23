#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int num, vector<int> &fibonacciSeries)
{
    fibonacciSeries.resize(num + 1, -1);
    fibonacciSeries[0]  = fibonacciSeries[1] = fibonacciSeries[2] = 1;

    for (int i = 3; i <= num; i++)
    {
        fibonacciSeries[i] = fibonacciSeries[i - 1] + fibonacciSeries[i - 2];
    }

    return fibonacciSeries[num];
}

int main(int argc, char *argv[])
{
    vector<int> fibonacciSeries;

    cout << fibonacci(40, fibonacciSeries);

    return 0;
}
