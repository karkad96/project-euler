#include <iostream>

using namespace std;

bool isPalindromic(int n)
{
    int res = 0;
    int tmp = n;

    while (tmp)
    {
        res = 10 * res + tmp % 10;
        tmp /= 10;
    }

    return res == n;
}

int main()
{
    int mx = 0;

    for (int i = 999; i >= 100; i--)
    {
        int res = 0;

        for (int j = i; j >= 100; j--)
        {
            if (isPalindromic(i * j))
            {
                res = i * j;
                break;
            }
        }

        if (mx < res)
            mx = res;
    }

    cout << mx << endl;

    return 0;
}

