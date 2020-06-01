#include <iostream>

using namespace std;

int power = 5;

int powers[] = { 0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768, 59049 };

bool digitPower(int n)
{
    int res = 0;
    int tmp = n;

    while (n)
    {
        res += powers[n % 10];
        n /= 10;
    }

    return tmp == res;
}

int main()
{
    int res = 0;

    for (int i = 2; i <= 1000000; i++)
    {
        if (digitPower(i))
        {
            res += i;
        }
    }

    cout << res << endl;

    return 0;
}