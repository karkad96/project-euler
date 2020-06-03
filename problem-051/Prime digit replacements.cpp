#include <iostream>

using namespace std;

const int N = 1000000;

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
    //We need to check only 'masks' with three replacements.

    ES();

    int masks[] = { 1, 10, 100, 1000, 10000, 100000 };

    bool flag = false;

    for (int n = 100000; n <= 1000000 and !flag; n++)
    if (primes[n])
    for (int i = 0; i < 6 and !flag; i++)
    for (int j = i + 1; j < 6 and !flag; j++)
    for (int k = j + 1; k < 6 and !flag; k++)
    if ((n / masks[i]) % 10 == (n / masks[j]) % 10 and (n / masks[i]) % 10 == (n / masks[k]) % 10)
    {
        int first = (n / masks[i]) % 10;
        int count = 0;
        int tmp_n;
    
        for (int d = first; d <= 9; d++)
        {
            tmp_n = n + (d - first) * masks[i] + (d - first) * masks[j] + (d - first) * masks[k];
    
            if (primes[tmp_n])
                count++;
        }
    
        if (count == 8)
        {
            cout << n << endl;
            flag = true;
            break;
        }
    }

    return 0;
}