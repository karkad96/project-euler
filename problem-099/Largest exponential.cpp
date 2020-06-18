#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;


int main()
{
    fstream file("base_exp.txt");
    string line;

    double mx = 0;
    int res = 0;
    int count = 0;

    while (getline(file, line))
    {
        char* pEnd;

        int a = strtol(line.c_str(), &pEnd, 10);
        int b = strtol(pEnd + 1, &pEnd, 10);
        count++;

        if (mx < b * log(a))
        {
            mx = b * log(a);
            res = count;
        }
    }

    cout << res << endl;

    return 0;
}