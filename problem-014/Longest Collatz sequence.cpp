#include <iostream>

using namespace std;

const int N = 1000000;

int cache[N + 1];

int main()
{
    cache[1] = 1;

    int mx = 0;
    int res = 1;

    for (int i = 2; i < N; i++)
    {
        long long int collatz = i;
        int count = 0;

        while (collatz != 1)
        {
            if (cache[i])
            {
                count += cache[i];
                break;
            }

            if (collatz % 2 == 1)
                collatz = 3 * collatz + 1;
            else
                collatz /= 2;
            count++;
        }

        cache[i] = count + 1;

        if (mx < count + 1)
        {
            mx = count + 1;
            res = i;
        }
    }

    cout << res << endl;

    return 0;
}
