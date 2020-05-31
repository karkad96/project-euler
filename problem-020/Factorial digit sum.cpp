#include <iostream>

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

string factorial(unsigned int  a)
{
    string res = "1";

    for (unsigned int i = 1; i <= a; i++)
    {
        res = multiply(res, i);
    }

    return res;
}

int main()
{
    string a = factorial(100);
    int res = 0;

    for (int i = 0; i < a.size(); i++)
        res += (int)a[i] - 48;

    cout << res << endl;

    return 0;
}
