#include <iostream>

using namespace std;

const int limit = 500000;

int mark[limit + 1];

int findNthPrime(int nth)
{
    for (int i = 0; i <= limit; i++)
        mark[i] = true;

    mark[0] = mark[1] = false;

    for (int i = 2; i * i <= limit; i++)
    {
        if (mark[i])
        {
            for (int j = i * i; j <= limit; j += i)
            {
                mark[j] = false;
            }
        }
    }

    for (int i = 0; i <= limit; i++)
    {
        if (mark[i])
            nth--;

        if (!nth)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    cout << findNthPrime(10001) << endl;

    return 0;
}
