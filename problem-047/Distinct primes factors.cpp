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

    int n = 213;

    bool n1 = true;
    bool n2 = false;
    bool n3 = false;
    bool n4 = false;

    while (!n1 or !n2 or !n3 or !n4)
    {
        n++;

        bool flag = false;

        int p = lnk[n];
        int tmp = n;
        int count = 0;

        while (p)
        {
            while (tmp % p == 0)
            {
                tmp /= p;
            }

            count++;

            p = lnk[tmp];
        }

        if (count == 4)
            flag = true;

        n1 = n2;
        n2 = n3;
        n3 = n4;
        n4 = flag;
    }

    cout << n - 3 << endl;

    return 0;
}