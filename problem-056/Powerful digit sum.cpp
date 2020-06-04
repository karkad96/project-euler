#include <iostream>
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

int digitalSum(string s)
{
    int sum = 0;

    for (unsigned int i = 0; i < s.size(); i++)
    {
        sum += (int)s[i] - 48;
    }

    return sum;
}

int main()
{
    int mx = 0;

    for (int a = 90; a < 100; a++)
    {
        for (int b = 90; b < 100; b++)
        {
            string s = power(a, b);
            int sum = digitalSum(s);

            if (mx < sum)
                mx = sum;
        }
    }

    cout << mx << endl;

    return 0;
}