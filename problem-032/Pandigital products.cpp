#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main()
{
    set<int> s;

    string perm = "123456789";

    int n, n2, res;
    int ans = 0;

    do
    {
        n = stoi(perm.substr(0, 1));
        n2 = stoi(perm.substr(1, 4));
        res = stoi(perm.substr(5, 4));

        if (n * n2 == res)
            s.insert(res);

        n = stoi(perm.substr(0, 2));
        n2 = stoi(perm.substr(2, 3));
        res = stoi(perm.substr(5, 4));

        if (n * n2 == res)
            s.insert(res);

    } while (next_permutation(perm.begin(), perm.end()));

    for (auto i : s)
        ans += i;

    cout << ans << endl;

    return 0;
}