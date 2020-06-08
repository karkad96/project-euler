#include <iostream>

using namespace std;

bool isPrime(int n)
{
    if (n == 2)
        return true;

    if (n > 2 and n % 2 == 0)
        return false;

    for (int i = 3; i * i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}

int main()
{
    const int N = 100;
    int it = 1, p;

    int primes[N + 1];
    int ways[N + 1] = { 0 };

    ways[0] = 1;
    primes[0] = 2;

    for (p = 3; p <= N; p += 2)
    {
        if (isPrime(p))
        {
            primes[it++] = p;
        }
    }

    for (int i = 0; i < it; i++)
    {
        for (int j = primes[i]; j <= N; j++)
        {
            ways[j] += ways[j - primes[i]];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (ways[i] > 5000)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}