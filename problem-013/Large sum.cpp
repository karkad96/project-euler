#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

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

int main()
{
    string line;
    string res = "";
    ifstream myfile("numbers.txt");

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            res = add(res, line);
        }

        myfile.close();
    }

    cout << res.substr(0, 10) << endl;

    return 0;
}
