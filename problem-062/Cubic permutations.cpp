#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

map<vector<int>, vector<int>> m;

int main()
{
    ll limit = 9000;

    for (ll i = 1; i <= limit; i++)
    {
        ll cube = i * i * i;

        vector<int> num;

        while (cube)
        {
            num.push_back(cube % 10);
            cube /= 10;
        }

        sort(num.begin(), num.end());

        m[num].push_back(i);

        if (m[num].size() == 5)
        {
            cout << m[num][0] << endl;
            break;
        }
    }

    return 0;
}