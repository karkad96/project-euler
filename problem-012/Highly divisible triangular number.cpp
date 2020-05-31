#include <iostream>

using namespace std;

//n and n + 1 are coprime numbers, so num_of_divisors(n*(n+1)) = num_of_divisors(n) * num_of_divisors(n + 1)

int getDivisorNumber(int n)
{
    if (n % 2 == 0)
        n /= 2;

    int res = 1;

    while (n % 2 == 0)
    {
        n /= 2;
        res++;
    }

    int p = 3;

    while (p * p <= n and n > 1)
    {
        int sum = 0;

        while (n % p == 0)
        {
            n /= p;
            sum++;
        }

        res = res * (sum + 1);

        p += 2;
    }

    if (n > 1)
        res *= 2;


    return res;
}

int main()
{
    int first = 1;
    int second = 2;
    int n = 2;

    while (first * second < 500)
    {
        first = second;
        second = getDivisorNumber(++n);
    }

    cout << (n - 1) * n / 2 << endl;

    return 0;
}

