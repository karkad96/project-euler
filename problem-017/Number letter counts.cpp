#include <iostream>
#include <map>

using namespace std;

map<int, int> m;

void init()
{
    m[0] = 0; m[1] = 3; m[2] = 3; m[3] = 5; m[4] = 4; m[5] = 4; m[6] = 3; m[7] = 5; m[8] = 5; m[9] = 4;
    m[10] = 3; m[11] = 6; m[12] = 6; m[13] = 8; m[14] = 8; m[15] = 7; m[16] = 7; m[17] = 9; m[18] = 9; m[19] = 8;
    m[20] = 6; m[30] = 6; m[40] = 5; m[50] = 5; m[60] = 5; m[70] = 7; m[80] = 6; m[90] = 6;
    m[100] = 10; m[200] = 10; m[300] = 12; m[400] = 11; m[500] = 11; m[600] = 10; m[700] = 12; m[800] = 12; m[900] = 11;
    m[1000] = 11;
}

int main()
{
    init();

    int res = m[1000];

    for (int i = 1; i < 1000; i++)
    {
        if (i <= 20)
            res += m[i];

        else if (i > 20 and i < 100)
            res += m[10 * (i / 10)] + m[i % 10];

        else if (i >= 100 and i % 100 <= 20)
            res += m[100 * (i / 100)] + m[i % 100] + 3;

        else
            res += m[100 * (i / 100)] + m[10 * ((i % 100) / 10)] + m[i % 10] + 3;
    }

    cout << res - 3 * 9 - 10 << endl;

    return 0;
}
