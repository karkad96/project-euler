#include <iostream>

using namespace std;

bool isPentagonal(int n)
{
    if (n <= 0)
        return false;

    double x = (sqrt(24 * n + 1) + 1) / 6.0;

    return x == (int)x;
}

int main()
{
    int i = 1, j = 1;
    bool flag = false;

    while (!flag)
    {
        j = 1;

        while (!flag and j <= i)
        {
            int diff = (i - j) * (3 * j + 3 * i - 1) / 2;
            int add = (3 * j * j - j + 3 * i * i - i) / 2;

            if (isPentagonal(diff) and isPentagonal(add))
            {
                cout << diff << endl;
                flag = true;
            }

            j++;
        }

        i++;
    }

    return 0;
}