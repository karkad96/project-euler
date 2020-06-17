#include <iostream>

using namespace std;

typedef long long int ll;

int main()
{
    const int N = 3;
    const ll limit = 1000000000;

    ll sqr = (ll)sqrt(N);
    ll m = 0;
    ll d = 1;
    ll a = sqr;

    ll kn = 1;
    ll hn = a;
    ll kn_1 = 0;
    ll kn_2;
    ll hn_1 = 1;
    ll hn_2;

    ll res = 0;

    ll a_n = 0;
    ll b_n = 0;
    ll area = 0;

    int sign = -1;

    while (area <= limit)
    {
        if (hn * hn - 3 * kn * kn == 1)
        {
            a_n = ((2 * hn - 1) % 3 == 0) ? (2 * hn - 1) / 3 : (2 * hn + 1) / 3;
            b_n = a_n + sign;

            sign = -sign;
            area = 2 * a_n + b_n;

            res += area;
        }

        m = d * a - m;
        d = (N - m * m) / d;
        a = (sqr + m) / d;

        kn_2 = kn_1;
        kn_1 = kn;
        hn_2 = hn_1;
        hn_1 = hn;

        hn = a * hn_1 + hn_2;
        kn = a * kn_1 + kn_2;
    }

    cout << res - area - 2 << endl;

    return 0;
}