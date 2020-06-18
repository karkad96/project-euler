#include "bigint.h"

using namespace std;

int main()
{
    const int N = 8;

    int sqr = (int)sqrt(N);
    int m = 0;
    int d = 1;
    int a = sqr;

    bigint kn = 1;
    bigint hn = a;
    bigint kn_1 = 0;
    bigint kn_2;
    bigint hn_1 = 1;
    bigint hn_2;

    long long int r_n = 0;
    long long int b_n = 0;

    while (r_n + b_n <= 1000000000001)
    {
        m = d * a - m;
        d = (N - m * m) / d;
        a = (sqr + m) / d;

        kn_2 = kn_1;
        kn_1 = kn;
        hn_2 = hn_1;
        hn_1 = hn;

        hn = hn_1 * a + hn_2;
        kn = kn_1 * a + kn_2;

        if (hn * hn - kn * kn * N == 1)
        {
            r_n = bigint::to_int64(kn);
            b_n = (2 * r_n + bigint::to_int64(hn) + 1) / 2;
        }
    }

    cout << b_n << endl;

    return 0;
}