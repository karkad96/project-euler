#include <iostream>

using namespace std;

//https://en.wikipedia.org/wiki/Zeller%27s_congruence

int main()
{
    int count = 0;

    for (int year = 1901; year <= 2000; year++)
    {
        for (int month = 3; month <= 14; month++)
        {
            int h = (1 + (13 * (month + 1)) / 5 + year % 100 + (year % 100) / 4 + (year / 100) / 4 + 5 * (year / 100)) % 7;

            if (h == 1)
                count++;
        }
    }

    cout << count << endl;

    return 0;
}
