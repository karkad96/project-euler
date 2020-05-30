#include <iostream>

using namespace std;

int d[] = { 1, 2, 4, 5, 10, 20, 25, 50, 100, 125, 250, 500 };

int main()
{
    int res = -1;

    for (auto m : d)
    {
        int n = 500 / m - m;

        if (n <= 0)
            break;

        if ((m + n) % 2 == 1 and m > n)
        {
            int a = m * m - n * n;
            int b = 2 * m * n;
            int c = m * m + n * n;

            res = a * b * c;
        }
    }

    cout << res << endl;

    return 0;
}
