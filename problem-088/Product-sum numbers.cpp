#include <iostream>
#include <set>

using namespace std;

const int N = 12000;
const int limit = 2 * N;

int mins[N + 1];

void solve(int n, int sum, int mul, int depth)
{
    int c = mul - sum + depth;

    if (c >= 0 and c <= N)
    {
        if (mins[c] > mul)
            mins[c] = mul;
    }

    for (int i = n; i <= limit and i * mul <= limit and i + sum <= limit; i++)
    {
        solve(i, i + sum, i * mul, depth + 1);
    }
}

int main()
{
    for (int i = 0; i <= N; i++)
        mins[i] = INT_MAX;

    solve(2, 1, 1, 1);

    set <int> s;

    for (int i = 2; i <= N; i++)
        s.insert(mins[i]);

    int res = 0;

    for (auto i : s)
        res += i;

    cout << res << endl;

    return 0;
}