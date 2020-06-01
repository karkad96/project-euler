#include <iostream>
#include <set>
#include <math.h>

using namespace std;

int main()
{
    set<double> s;

    for (double a = 2; a <= 100; a++)
    {
        for (double b = 2; b <= 100; b++)
        {
            s.insert(pow(a, b));
        }
    }

    cout << s.size() << endl;

    return 0;
}
