#include <iostream>

using namespace std;

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
    bool flag = false;
    int from = 100;
    int to = 166;

    while (!flag)
    {
        int i = from;

        while (i != to)
        {
            int count = 0;

            for (int n = 2; n <= 6; n++)
            {
                if (isPermutation(i, i * n))
                {
                    count++;
                }
            }

            if (count == 5)
            {
                cout << i << endl;
                flag = true;
                break;
            }

            i++;
        }

        from *= 10;
        to = 10 * to + 6;
    }

    return 0;
}