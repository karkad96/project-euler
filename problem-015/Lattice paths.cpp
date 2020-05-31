#include <iostream>

using namespace std;

typedef long long int ll;

ll latticePath(int n, int m)
{
    ll num = 1;
    ll den = 1;
    ll to = n > m ? m : n;

    for (int p = n + m; p > to; p--)
    {
        num = num * p / (den++);
    }

    return num;
}

int main()
{
    cout << latticePath(20, 20) << endl;

    return 0;
}