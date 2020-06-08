#include <iostream>
#include <map>

using namespace std;

int fac[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

const int N = 10000000;

int sum_fac[N + 1];
int chain_length[N + 1];

int digitalSumFac(int n)
{
    int res = 0;

    while (n)
    {
        res += fac[n % 10];
        n /= 10;
    }

    return res;
}

int nextTerm(int n)
{
    if (n <= N)
        return sum_fac[n];

    else return digitalSumFac(n);
}

int main()
{
    sum_fac[0] = 1;

    int res = 0;

    for (int i = 1; i <= N; i++)
    {
        sum_fac[i] = digitalSumFac(i);
    }

    for (int i = 1; i <= 1000000; i++)
    {
        int tmp = i;

        map<int, int> m;

        int count = 0;

        while (m.find(tmp) == m.end())
        {
            if (chain_length[tmp])
            {
                count += chain_length[tmp];
                break;
            }
            else
            {
                m[tmp] = 1;
                count++;
                tmp = nextTerm(tmp);
            }
        }

        chain_length[i] = count;

        if (count == 60)
            res++;
    }

    cout << res << endl;

    return 0;
}