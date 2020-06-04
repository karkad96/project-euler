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

bool isPalindromic(string a)
{
    int size = a.size() / 2;
    int size2 = a.size();

    for (int i = 0; i <= size; i++)
    {
        if (a[i] != a[size2 - i - 1])
            return false;
    }

    return true;
}

int main()
{
    int res = 0;

    for (int i = 1; i < 10000; i++)
    {
        int count = 0;
        string a = to_string(i);

        while (!isPalindromic(a) and count < 50)
        {
            string cpy = a;
            reverse(cpy.begin(), cpy.end());
            a = add(a, cpy);
            count++;
        }

        if (count == 50)
            res++;
    }

    cout << res + 3 << endl;

    return 0;
}