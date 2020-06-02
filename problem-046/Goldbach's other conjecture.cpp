#include <iostream>

using namespace std;

const int N = 10000;

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
    ES();

    int n = 1;
    bool flag = false;

    while (!flag)
    {
        n += 2;

        if (primes[n])
            continue;

        flag = true;

        for (int i = 2; i <= N and i < n; i++)
        {
            if (primes[i])
            {
                int tmp_n = i;
                int j = 1;

                while (tmp_n < n)
                {
                    tmp_n = i + 2 * j * j;
                    j++;
                }

                if (tmp_n == n)
                {
                    flag = false;
                    break;
                }
            }
        }
    }

    cout << n << endl;

    return 0;
}