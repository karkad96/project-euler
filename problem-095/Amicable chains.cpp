#include <iostream>

using namespace std;

const int N = 1000000;

int sigma1[N + 1];
int cache[N + 1];

void sieve()
{
    sigma1[1] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 2 * i; j <= N; j += i)
        {
            sigma1[j] += i;
        }
    }
}

int main()
{
    sieve();

    int mx = 0;
    int res = 0;

    for (int i = 2; i <= N; i++)
    {
        int tmp = i;
        int count = 0;
        int it = 0;
        int k;

        cache[it++] = i;

        do
        {
            tmp = sigma1[tmp];
            if (tmp > N)
                break;
            for (k = 0; k < it; k++)
                if (cache[k] == tmp)
                    break;
            if (k != it)
                break;
            count++;
            cache[it++] = tmp;

        } while (tmp != 1 and tmp != i);

        if (i == tmp)
        {
            if (mx < count)
            {
                mx = count;
                res = tmp;
            }
        }
    }

    cout << res << endl;

    return 0;
}