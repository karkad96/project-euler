#include <iostream>

using namespace std;

const int N = 1000;

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

int main()
{
    int mx = 0;
    int real_a = 0;
    int real_b = 0;

    ES();

    for (int b = 2; b <= N; b++)
    {
        if (primes[b])
        {
            for (int a = -N + 1; a < N; a++)
            {
                int n = 0;
                int count = 0;

                while (n * n + a * n + b >= 0 and
                    n * n + a * n + b <= N and
                    primes[n * n + a * n + b])
                {
                    n++;
                    count++;
                }

                if (mx < count)
                {
                    mx = count;
                    real_b = b;
                    real_a = a;
                }
            }
        }
    }

    cout << real_a * real_b << endl;

    return 0;
}
