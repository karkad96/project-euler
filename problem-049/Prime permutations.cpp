#include <iostream>

using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    if (n % 2 == 0)
        return false;

    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

bool isPermutation(int n, int k)
{
    int t1[10] = { 0 };
    int t2[10] = { 0 };

    while (n)
    {
        t1[n % 10]++;
        n /= 10;
    }

    while (k)
    {
        t2[k % 10]++;
        k /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        if (t1[i] != t2[i])
            return false;
    }

    return true;
}

int main()
{
    int flag = false;

    for (int i = 9999; i >= 1000 and !flag; i -= 2)
    {
        if (isPrime(i))
        {
            int a = 1;
            int i2 = i - a;
            int i3 = i - 2 * a;

            while (i3 > 0)
            {
                a++;
                i2 = i - a;
                i3 = i - 2 * a;

                if (isPrime(i2) and isPrime(i3) and isPermutation(i, i2) and isPermutation(i, i3))
                {
                    cout << i3 << i2 << i << endl;
                    flag = true;
                    break;
                }
            }
        }
    }

    return 0;
}