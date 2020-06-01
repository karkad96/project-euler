#include <iostream>

using namespace std;

const int N = 1000000;

int primes[N + 1];

void ES()
{
    for (int i = 0; i <= N; i++)
        primes[i] = true;

    primes[0] = primes[1] = false;

    for (int i = 2; i * i <= N; i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                primes[j] = false;
            }
        }
    }
}

int length(int n)
{
    return (int)log10(n) + 1;
}

bool isTruncable(int n)
{
    int size = (int)pow(10, length(n) - 1);
    int n2 = n;

    while (n)
    {
        if (!primes[n] or !primes[n2])
            return false;

        n /= 10;
        n2 = n2 % size;
        size /= 10;
    }

    return true;
}

int main()
{
    int res = 0;

    ES();

    for (int i = 11; i <= N; i++)
    {
        if (primes[i] and isTruncable(i))
            res += i;
    }

    cout << res << endl;

    return 0;
}