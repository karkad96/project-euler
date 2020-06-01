#include <iostream>

using namespace std;

const int N = 10000000;

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

bool isCircular(int n)
{
    int size = length(n);
    int mask = (int)pow(10, size - 1);

    while (--size)
    {
        n = 10 * (n % mask) + n / mask;

        if (!primes[n])
            return false;
    }

    return true;
}

int main()
{
    ES();

    int count = 1;

    for (int i = 3; i < 1000000; i += 2)
    {
        if (primes[i] and isCircular(i))
            count++;
    }

    cout << count << endl;

    return 0;
}