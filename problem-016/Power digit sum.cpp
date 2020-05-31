#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string multiply(string a, unsigned int b)
{
    string res = "";

    unsigned int mx = a.size();

    int carry = 0;

    for (int i = mx - 1; i >= 0; i--)
    {
        int mul = ((int)a[i] - 48) * b;
        res = (char)((mul + carry) % 10 + 48) + res;
        carry = (mul + carry) / 10;
    }

    while (carry)
    {
        res = (char)(carry % 10 + 48) + res;
        carry /= 10;
    }

    return res;
}

string power(unsigned int  a, unsigned int b)
{
    string res = "1";

    for (unsigned int i = 0; i < b; i++)
    {
        res = multiply(res, a);
    }

    return res;
}

int main()
{
    string p = power(2, 1000);

    int ans = 0;

    for (unsigned int i = 0; i < p.size(); i++)
        ans += ((int)p[i] - 48);

    cout << ans << endl;

    return 0;
}
