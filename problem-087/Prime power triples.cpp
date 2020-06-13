#include <iostream>

using namespace std;

typedef long long int ll;

const int limit = 50000000;
const int N = 7071;

int primes[N + 1];
int lnk[N + 1];
int nums[limit];

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

    for (int i = 1; i <= size; i++)
    {
        ll it = primes[i];

        if (it * it < limit)
        {
            for (int j = 1; j <= size; j++)
            {
                ll jt = primes[j];

                if (it * it + jt * jt * jt < limit)
                {
                    for (int k = 1; k <= size; k++)
                    {
                        ll kt = primes[k];

                        if (kt * kt * kt * kt >= limit)
                            break;

                        if (it * it + jt * jt * jt + kt * kt * kt * kt >= limit)
                            break;

                        nums[it * it + jt * jt * jt + kt * kt * kt * kt]++;
                    }
                }
            }
        }
    }

    int res = 0;

    for (int i = 0; i < limit; i++)
        if (nums[i])
            res++;

    cout << res << endl;

    return 0;
}