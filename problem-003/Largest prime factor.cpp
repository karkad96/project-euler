#include <iostream>

using namespace std;

typedef long long int ll;

ll largestPrimeFactor(ll n)
{
    while (n % 2 == 0)
        n /= 2;

    if (n == 1)
        return 2;

    ll p = 3;
    ll largest = 2;

    while (p * p <= n and n > 1)
    {
        while (n % p == 0)
        {
            n /= p;
            largest = p;
        }

        p += 2;
    }

    if (n > 1)
        largest = n;

    return largest;
}

int main()
{
    ll num = 600851475143;

    cout << largestPrimeFactor(49) << endl;

    return 0;
}

