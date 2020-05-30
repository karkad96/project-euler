#include <iostream>

using namespace std;

typedef long long int ll;

int main()
{
    int limit = 4000000;

    int f1 = 1;
    int f2 = 2;
    int fn = 0;
    int sum = 0;

    while (f1 + f2 < limit)
    {
        fn = f1 + f2;

        if (fn % 2 == 0)
            sum += fn;

        f1 = f2;
        f2 = fn;
    }

    cout << sum + 2 << endl;

    return 0;
}
