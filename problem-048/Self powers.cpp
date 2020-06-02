#include <iostream>

using namespace std;

typedef long long int ll;

int main()
{
    ll mod = 10000000000;
    ll res = 0;

    for (ll i = 1; i <= 1000; i++)
    {
        ll a = 1;

        for (ll j = 1; j <= i; j++)
        {
            a = (a * i) % mod;
        }

        res = (res + a) % mod;
    }

    cout << res << endl;

    return 0;
}