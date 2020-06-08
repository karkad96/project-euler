#include <iostream>

using namespace std;

//https://en.wikipedia.org/wiki/Farey_sequence

const int N = 1000000;

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


int main()
{
    long long int  res = 0;

    totientSieve();

    for (int i = 2; i <= N; i++)
        res += tot[i];

    cout << res << endl;

    return 0;
}