#include "bigint.h"

int main()
{
    bigint hundred(100);
    bigint ten(10);
    bigint ff(45);
    bigint a;
    bigint b;

    int sum = 0;

    for (int n = 2; n < 100; n++)
    {
        if (((sqrt(n) - floor(sqrt(n))) == 0))
            continue;

        int start = 5 * n;

        bigint a(start);
        bigint b(5);

        int count = 0;

        while (count++ < 610)
        {
            if (a >= b)
            {
                a -= b;
                b += 10;
            }
            else
            {
                a = hundred * a;
                b = ten * b - ff;
            }
        }

        for (int i = 0; i < 100; i++)
            sum += b[i];
    }

    cout << sum << endl;

    return 0;
}