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

bool simplifyWrong(int a, int b)
{
    int a1 = a / 10;
    int a2 = a % 10;

    int b1 = b / 10;
    int b2 = b % 10;

    int g = gcd(a, b);
    int g2;

    a /= g, b /= g;

    if (a2 == 0 and b2 == 0)
        return false;

    if (a1 == b1)
    {
        g2 = gcd(a2, b2);
        a2 /= g2, b2 /= g2;

        return a2 * b == b2 * a;
    }
    else if (a1 == b2)
    {
        g2 = gcd(a2, b1);
        a2 /= g2, b1 /= g2;

        return a2 * b == b1 * a;
    }
    else if (a2 == b1)
    {
        g2 = gcd(a1, b2);
        a1 /= g2, b2 /= g2;

        return a1 * b == b2 * a;
    }
    else if (a2 == b2)
    {
        g2 = gcd(a1, b1);
        a1 /= g2, b1 /= g2;

        return a1 * b == b1 * a;
    }

    return false;
}

int main()
{
    int up = 1;
    int down = 1;

    for (int num = 10; num <= 99; num++)
    {
        for (int den = num + 1; den <= 99; den++)
        {
            if (simplifyWrong(num, den))
            {
                up *= num;
                down *= den;
            }
        }
    }

    down = down / gcd(up, down);

    cout << down << endl;

    return 0;
}