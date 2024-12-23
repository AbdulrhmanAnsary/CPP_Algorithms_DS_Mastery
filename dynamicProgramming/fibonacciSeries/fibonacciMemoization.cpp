#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int num, vector<int> &fibonacciSeries)
{
    if (num > 2)
    {
        if (fibonacciSeries.size() <= num)
        {
            fibonacciSeries.resize(num + 1, -1);
        }

        if (fibonacciSeries[num] == -1)
        {
            fibonacciSeries[num] = fibonacci(num - 1, fibonacciSeries) + fibonacci(num - 2, fibonacciSeries);
        }

        return fibonacciSeries[num];
    }

    return 1;
}

int main(int argc, char *argv[])
{
    vector<int> fibonacciSeries;

    cout << fibonacci(40, fibonacciSeries);

    return 0;
}