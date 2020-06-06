#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string add(string a, string b)
{
    string res = "";

    unsigned int mx = max(a.size(), b.size());

    while (a.size() < mx)
        a = '0' + a;

    while (b.size() < mx)
        b = '0' + b;

    int carry = 0;

    for (int i = mx - 1; i >= 0; i--)
    {
        int sum = (int)a[i] + (int)b[i] - 96;
        res = (char)((sum + carry) % 10 + 48) + res;
        carry = (sum + carry) / 10;
    }

    if (carry)
        res = (char)(carry + 48) + res;

    return res;

}

string multiply(string num1, string num2)
{
    if (num1.size() == 0 || num2.size() == 0) return "";

    string ret(num1.size() + num2.size() + 1, '0');

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    for (unsigned int i = 0; i < num2.size(); i++)
    {
        int dig2 = num2[i] - '0';
        int carry = 0;

        for (unsigned int j = 0; j < num1.size(); j++)
        {
            int dig1 = num1[j] - '0';
            int temp = ret[i + j] - '0';
            int cur = dig1 * dig2 + temp + carry;
            ret[i + j] = cur % 10 + '0';
            carry = cur / 10;
        }

        ret[i + num1.size()] = carry + '0';
    }

    reverse(ret.begin(), ret.end());

    unsigned int pos = ret.find_first_not_of('0', 0);

    if (pos < 0 || pos >= ret.size())
        pos = ret.size() - 1;

    return ret.substr(pos, ret.size() - pos);
}

int main()
{
    string kn;
    string hn;
    string kn_1 = "1";
    string kn_2 = "1";
    string hn_1 = "3";
    string hn_2 = "2";
    string an = "2";

    int a = 0;
    int count = 0;

    for (int i = 3; i <= 100; i++)
    {
        if ((i - 3) % 3 == 0)
        {
            a += 2;
            an = to_string(a);
        }
        else
            an = "1";

        hn = add(multiply(an, hn_1), hn_2);
        kn = add(multiply(an, kn_1), kn_2);

        kn_2 = kn_1;
        hn_2 = hn_1;
        hn_1 = hn;
        kn_1 = kn;
    }

    int sum = 0;

    for (unsigned int i = 0; i < hn.size(); i++)
        sum += (int)hn[i] - 48;

    cout << sum << endl;

    return 0;
}