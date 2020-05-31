#include <iostream>

using namespace std;

const int N = 28123;

int nonAbundant[N + 1];
int abundant[N + 1];

int divisorSum(int n)
{
    int tmp = n;
    int sum = 1;
    int p = 2;

    while (p * p <= n and n > 1)
    {
        if (n % p == 0)
        {
            int j = p * p;
            n /= p;

            while (n % p == 0)
            {
                j *= p;
                n /= p;

            }
            sum *= j - 1;
            sum /= p - 1;
        }

        if (p == 2)
            p = 3;
        else
            p += 2;
    }

    if (n > 1)
        sum *= n + 1;

    return sum - tmp;
}

int main()
{
    int it = 0;
    for (int i = 12; i <= N; i++)
    {
        if (divisorSum(i) > i)
        {
            abundant[it++] = i;
        }
    }

    for (int i = 0; i < it; i++)
    {
        for (int j = i; j < it; j++)
        {
            int sum = abundant[i] + abundant[j];

            if (sum <= N)
            {
                nonAbundant[sum]++;
            }
        }
    }

    int res = 0;

    for (int i = 1; i <= N; i++)
    {
        if (!nonAbundant[i])
            res += i;
    }

    cout << res << endl;

    return 0;
}
