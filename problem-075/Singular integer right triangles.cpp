#include <iostream>

using namespace std;

const int limit = 1500000;

int perimeters[limit + 1];

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

int main()
{
    for (int m = 1; 2 * m * m <= limit; m++)
    {
        for (int n = 1; n < m and 2 * m * m + 2 * m * n <= limit; n++)
        {
            if (gcd(n, m) != 1 or (m + n) % 2 == 0)
                continue;

            int k = 1;

            while (k * (2 * m * m + 2 * m * n) <= limit)
            {
                perimeters[k * (2 * m * m + 2 * m * n)]++;
                k++;
            }
        }
    }

    int res = 0;

    for (int i = 12; i <= limit; i++)
        if (perimeters[i] == 1)
            res++;

    cout << res << endl;

    return 0;
}