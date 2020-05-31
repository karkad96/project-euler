#include <iostream>

using namespace std;

//Max recurring cycle in decimal form is for some prime p and its length is p - 1.
//So we only have to find first prime number < 1000 that satisfies this relation.

bool isPrime(int n)
{
    if (n % 2 == 0)
        return false;

    for (int i = 3; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int recurringLength(int n)
{
    while (n % 2 == 0)
        n /= 2;

    while (n % 5 == 0)
        n /= 5;

    int next = 1;
    int count = 0;

    for (int i = 0; i < n; i++) next = (next * 10) % n;

    int first = next;

    do
    {
        next = (next * 10) % n;
        count++;
    } while (first != next);

    return count;
}

int main()
{
    for (int d = 999; d >= 1; d--)
    {
        if (isPrime(d))
        {
            if (recurringLength(d) == d - 1)
            {
                cout << d << endl;
                break;
            }
        }
    }

    return 0;
}
