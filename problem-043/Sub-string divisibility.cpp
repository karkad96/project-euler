#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

bool isPandigital3(int n)
{
    int t[10] = { 0 };

    while (n)
    {
        t[n % 10]++;
        n /= 10;
    }

    for (auto i : t)
    {
        if (i > 1)
            return false;
    }

    return true;
}

bool isPandigital(ll n)
{
    int res = 0;

    while (n)
    {
        res = res | (1 << (n % 10));
        n /= 10;
    }

    return 1 << 10 == res + 1;
}

int main()
{
    int divs[] = { 2, 3, 5, 7, 11, 13, 17 };

    vector < vector <int> > v;

    for (auto i : divs)
    {
        vector<int> nums;

        for (int j = 0; j <= 999; j++)
        {
            if (isPandigital3(j) and j % i == 0)
                nums.push_back(j);
        }

        v.push_back(nums);
    }
    
    ll res = 0;

    for (auto i: v[0])
    for (auto j : v[1])
    if (i % 100 == j / 10)
    for (auto k : v[2])
    if (j % 100 == k / 10)
    for (auto l : v[3])
    if (k % 100 == l / 10)
    for (auto m : v[4])
    if (l % 100 == m / 10)
    for (auto n : v[5])
    if (m % 100 == n / 10)
    for (auto o : v[6])
    if (n % 100 == o / 10 and i>=100)
        for (ll p = 1; p <= 9; p++)
        {
            ll num = 1000000000 * p + i * 1000000 + (j % 10) * 100000 + (k % 10) * 10000 + (l % 10) * 1000 + (m % 10) * 100 + (n % 10) * 10 + o % 10;
             
            if (isPandigital(num))
                res += num;
        }
    
    cout << res << endl;

    return 0;
}