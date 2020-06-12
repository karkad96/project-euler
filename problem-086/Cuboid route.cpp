#include <iostream>
#include <algorithm>

using namespace std;

int limit = 1000000;

int gcd(int a, int b)
{
    int pom;

    while (b != 0)
    {
        pom = b;
        b = a % b;
        a = pom;
    }

    return a;
}

int cuboidRoutes(int M)
{
    int res = 0;

    for (int m = 2; m <= M; m++)
    {
        for (int n = 1; n < m; n++)
        {
            if ((n + m) % 2 == 0 or gcd(m, n) != 1)
                continue;

            int a = min(m * m - n * n, 2 * m * n);
            int b = max(m * m - n * n, 2 * m * n);

            int inc_a = a;
            int inc_b = b;

            while (a <= M)
            {
                if (b <= M)
                    res += a / 2;

                int c = (b / 2) - (b - a) + 1;

                if (c > 0)
                    res += c;

                a += inc_a;
                b += inc_b;
            }
        }
    }

    return res;
}

int main()
{
    int L = 1;
    int U = 2;
    int mid = 0;

    while (cuboidRoutes(U) < limit)
    {
        U *= 2;
        L *= 2;
    }

    while (L <= U)
    {
        mid = (L + U) / 2;

        int c = cuboidRoutes(mid);

        if (c < limit)
            L = mid + 1;
        else if (c > limit)
            U = mid - 1;
        else
            break;
    }

    cout << mid + 1 << endl;

    return 0;
}