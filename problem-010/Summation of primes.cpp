#include <iostream>

using namespace std;

const int limit = 2000000;

int mark[limit + 1];

long long int primeSum()
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

    long long int res = 0;

    for (int i = 0; i <= limit; i++)
    {
        if (mark[i])
            res += i;
    }

    return res;
}

int main()
{
    cout << primeSum() << endl;

    return 0;
}
