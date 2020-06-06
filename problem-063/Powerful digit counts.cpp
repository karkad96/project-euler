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

int main()
{
    int count = 0;

    for (int i = 1; i <= 9; i++)
    {
        int p = 1;
        string num = to_string(i);

        while (num.size() == p)
        {
            count++;
            p++;
            num = power(i, p);
        }
    }

    cout << count << endl;

    return 0;
}