#include <iostream>

using namespace std;

int divisorSum(int n)
{
    int tmp = n;
    int sum = 1;
    int p = 2;

    while (p * p <= n and n > 1)
    {
        if (n % p == 0)
        {
            int j = p * p;
            n /= p;

            while (n % p == 0)
            {
                j *= p;
                n /= p;

            }
            sum *= j - 1;
            sum /= p - 1;
        }

        if (p == 2)
            p = 3;
        else
            p += 2;
    }

    if (n > 1)
        sum *= n + 1;

    return sum - tmp;
}

int main()
{
    int res = 0;

    for (int a = 1; a < 10000; a++)
    {
        int b = divisorSum(a);

        if (b > a)
        {
            if (divisorSum(b) == a)
            {
                res += a + b;
            }
        }
    }

    cout << res << endl;

    return 0;
}
