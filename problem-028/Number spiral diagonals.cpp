#include <iostream>

using namespace std;

const int N = 1001;

int main()
{
    int sum = 1;

    for (int i = 3; i <= N; i += 2)
        sum += 4 * i * i - 6 * i + 6;

    cout << sum << endl;

    return 0;
}
