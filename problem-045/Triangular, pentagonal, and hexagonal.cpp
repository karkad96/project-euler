#include <iostream>

using namespace std;

int main()
{
    long long int i = 143;
    long long int h = 143;
    double x;

    do
    {
        i++;
        h = i * (2 * i - 1);
        x = (sqrt(24 * h + 1) + 1) / 6.0;
    } while (x != (int)x);

    cout << h << endl;

    return 0;
}