#include <iostream>

using namespace std;

const int N = 10000000;

int tot[N + 1];

void totientSieve()
{
    for (int i = 0; i <= N; i++)
        tot[i] = i;

    for (int i = 2; i <= N; i++)
    {
        if (tot[i] == i)
        {
            tot[i] = i - 1;

            for (int j = 2 * i; j <= N; j += i)
            {
                tot[j] = (tot[j] / i) * (i - 1);
            }
        }
    }
}

bool isPermutation(int n, int k)
{
    int res[10] = { 0 };

    while (n)
    {
        res[n % 10]++;
        n /= 10;
    }

    while (k)
    {
        res[k % 10]--;
        k /= 10;
    }

    for (int i = 0; i < 10; i++)
        if (res[i] != 0)
            return false;

    return true;
}

int main()
{
    totientSieve();

    double mn = (double)INT_MAX;
    int res = 0;

    for (int i = 2; i <= N; i++)
    {
        if (isPermutation(i, tot[i]) and mn > (double)i / tot[i])
        {
            mn = (double)i / tot[i];
            res = i;
        }
    }

    cout << res << endl;

    return 0;
}