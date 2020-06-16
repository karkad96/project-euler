#include <iostream>

using namespace std;

const int N = 10000000;

int cache[N + 1];

int squareDigitSum(int n)
{
    int res = 0;

    while (n)
    {
        res += (n % 10) * (n % 10);
        n /= 10;
    }

    return res;
}

int main()
{
    for (int i = 1; i <= N; i++)
    {
        int tmp = i;

        while (tmp != 1 and tmp != 89)
        {
            if (cache[tmp])
            {
                tmp = cache[tmp];
                break;
            }

            tmp = squareDigitSum(tmp);

        }

        cache[i] = tmp;
    }

    int res = 0;

    for (int i = 1; i <= N; i++)
        if (cache[i] == 89)
            res++;

    cout << res << endl;

    return 0;
}