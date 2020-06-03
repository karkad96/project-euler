#include <iostream>

using namespace std;

const int N = 1000000;

int primes[N + 1];
int lnk[N + 1];

int main()
{
    for (int i = 2; i <= N; ++i)
    {
        if (!primes[i])
            primes[++primes[0]] = i, lnk[i] = i;

        for (int j = 1, k = N / i; primes[j] <= k; ++j)
        {
            int t = i * primes[j];
            primes[t] = 1;
            lnk[t] = primes[j];

            if (i % primes[j] == 0)
                break;
        }
    }

    int size = primes[0];
    int mx = 0;
    int res = 0;

    for (int i = 5; i <= size; i++)
    {
        int tmp = primes[i];
        int it = 1;
        int k = 1;

        while (primes[i] > primes[it])
        {
            while (tmp > 0)
                tmp -= primes[it++];

            while (tmp < 0)
                tmp += primes[k++];

            if (tmp == 0)
            {
                if (mx < it - k)
                {
                    mx = it - k;
                    res = primes[i];
                }

                break;
            }
        }
    }

    cout << res << endl;

    return 0;
}