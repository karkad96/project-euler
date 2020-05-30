#include <iostream>

using namespace std;

int main()
{
    int num = 100;
    int sumSquare = num * (num + 1) * (2 * num + 1) / 6;
    int SquareSum = num * num * (num + 1) * (num + 1) / 4;
    int diff = SquareSum - sumSquare;

    diff = (diff < 0) ? -diff : diff;

    cout << diff << endl;

    return 0;
}