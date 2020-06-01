#include <iostream>

using namespace std;

int length(int n)
{
    if (n == 0)
        return 1;

    return (int)log10(n) + 1;
}

bool isPandigital(int n)
{
    int res = 0;

    while (n)
    {
        res = res | (1 << (n % 10));
        n /= 10;
    }

    return (1 << 10) == res + 2;
}

int main()
{
    int res = 0;

    for (int i = 1; i <= 10000; i++)
    {
        int n = 1;
        int size = 0;
        int num = 0;

        while (length(num) + length(n * i) <= 9)
        {
            num = num * size + n * i;
            n++;
            size = (int)pow(10, length(n * i));
        }

        if (isPandigital(num))
            res = num;

    }

    cout << res << endl;

    return 0;
}