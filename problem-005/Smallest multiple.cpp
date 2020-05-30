#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    int pom;

    while (b != 0)
    {
        pom = b;
        b = a % b;
        a = pom;
    }

    return a;
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int res = 1;

    for (int i = 1; i < 20; i++)
        res = lcm(res, i);

    cout << res << endl;

    return 0;
}
