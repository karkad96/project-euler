#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;

    int mod = 1000000;
    int n = 1;

    v.push_back(1);

    while (v[n - 1])
    {
        int seed = 1;
        int sign = 1;
        int res = 0;
        int count = 0;

        while (n - seed >= 0)
        {
            if (count % 4 > 1)
                sign = -1;
            else
                sign = 1;

            res = (res + sign * v[n - seed]) % mod;

            count++;
            int next = (count % 2 == 0) ? count / 2 + 1 : -(count / 2 + 1);
            seed = next * (3 * next - 1) / 2;
        }

        v.push_back(res);

        n++;
    }

    cout << n - 1 << endl;

    return 0;
}