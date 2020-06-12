#include <iostream>

using namespace std;

typedef long long int ll;

int main()
{
    ll nearest = INT_MAX;
    ll area = 0;

    for (ll i = 1413; i >= 1; i--)
    {
        for (ll j = 1; j <= 1413; j++)
        {
            ll res = i * (i + 1) * j * (j + 1) / 4;

            if (abs(res - 2000000) < nearest)
            {
                nearest = abs(res - 2000000);
                area = i * j;
            }
        }
    }

    cout << area << endl;

    return 0;
}