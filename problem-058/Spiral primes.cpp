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

bool isPrime(int n)
{
    if (n <= N)
        return primes[n];

    if (n <= 1)
        return false;

    if (n > 2 and n % 2 == 0)
        return false;

    for (int i = 3; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;

}

int main()
{
    ES();

    int n = 4;
    int diag_num = 13;
    int count = 8;

    while (10 * count >= diag_num)
    {
        diag_num += 4;
        n++;

        int d1 = 4 * n * n - 10 * n + 7;
        int d2 = 4 * n * n - 8 * n + 5;
        int d3 = 4 * n * n - 6 * n + 3;

        if (isPrime(d1))
            count++;
        if (isPrime(d2))
            count++;
        if (isPrime(d3))
            count++;
    }

    cout << 2 * n - 1 << endl;

    return 0;
}