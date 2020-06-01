#include <iostream>

using namespace std;

int factorials[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

bool factorialDigitsSum(int n)
{
    int tmp = n;
    int res = 0;

    while (n)
    {
        res += factorials[n % 10];
        n /= 10;
    }

    return tmp == res;
}

int main()
{
    int res = 0;

    for (int i = 10; i <= 10000000; i++)
    {
        if (factorialDigitsSum(i))
        {
            res += i;
        }
    }

    cout << res << endl;

    return 0;
}