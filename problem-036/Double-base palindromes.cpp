#include <iostream>

using namespace std;

const int N = 1000000;

bool isPalindrome(int n)
{
    int rev = 0;
    int tmp = n;

    while (tmp)
    {
        rev = 10 * rev + tmp % 10;
        tmp /= 10;
    }

    return rev == n;
}

int makePalindromeBase2(int n, bool length)
{
    int res = n;

    if (length)
        n = n >> 1;

    while (n)
    {
        res = (res << 1) + (n & 1);
        n >>= 1;
    }

    return res;
}

int main()
{
    int sum = 0;
    int i = 1;
    int p = makePalindromeBase2(i, true);

    while (p < N)
    {
        if (isPalindrome(p))
            sum += p;
        i++;
        p = makePalindromeBase2(i, true);
    }

    i = 1;
    p = makePalindromeBase2(i, false);

    while (p < N)
    {
        if (isPalindrome(p))
            sum += p;
        i++;
        p = makePalindromeBase2(i, false);
    }

    cout << sum << endl;

    return 0;
}