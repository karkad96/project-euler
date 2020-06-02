#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isPandigital(int n, int size)
{
    int res = 0;

    while (n)
    {
        res = res | (1 << (n % 10));
        n /= 10;
    }

    return 1 << (size + 1) == res + 2;
}

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

int main()
{
    vector<int> v = { 7, 6, 5, 4, 3, 2, 1 };

    int res;

    while (v.size())
    {
        int flag = false;

        do
        {
            int size = 0;
            res = 0;

            for (auto i : v)
            {
                res = 10 * res + i;
                size *= 10;
            }

            if (isPandigital(res, v.size()) and isPrime(res))
            {
                flag = true;
                cout << res << endl;
                break;
            }

        } while (prev_permutation(v.begin(), v.end()));

        if (flag)
            break;

        v.pop_back();
        sort(v.begin(), v.end(), greater<int>());
    }

    return 0;
}