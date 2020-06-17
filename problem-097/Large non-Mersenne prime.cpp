#include <iostream>

using namespace std;

typedef unsigned long long int ll;

int main()
{
    const ll mod = 10000000000;
    ll res = 1;

    for (int i = 1; i <= 7830457; i++)
    {
        res = (2 * res) % mod;
    }

    cout << (28433 * res + 1) % mod << endl;

    return 0;
}