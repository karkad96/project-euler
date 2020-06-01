#include <iostream>

using namespace std;

int length(int n)
{
    return (int)log10(n) + 1;
}

int main()
{
    int digits[] = { 1, 10, 100, 1000, 10000, 100000, 1000000 };
    int size = 0;
    int it = 0;
    int n = 1;
    int res = 1;

    while (it < 7)
    {
        size += length(n);

        if (size >= digits[it])
        {
            res *= n / (int)pow(10, size - digits[it]) % 10;
            it++;
        }

        n++;
    }

    cout << res << endl;

    return 0;
}