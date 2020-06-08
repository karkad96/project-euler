#include <iostream>
#include <string>

using namespace std;

string mx;

bool compare(string a, string b)
{
    if (a.size() < b.size())
        return true;
    else if (a.size() > b.size())
        return false;

    for (unsigned int i = 0; i < a.length(); ++i)
        if ((a[i] - '0') < (b[i] - '0'))
            return true;

    return false;
}


bool validString(string s)
{
    const int N = 15;

    int t[N] = { 0 };

    int it = 0;
    int i = 0;
    int j = 1;

    while (i < N)
    {
        if (s[i] == '1' and s[j] == '0')
        {
            t[it++] = 10;
        }
        else if (s[i] != '0')
        {
            t[it++] = (int)s[i] - '0';
        }

        i++;
        j++;
    }

    int a = t[0];
    i = 3;

    while (i < N)
    {
        if (a > t[i])
            return false;
        i += 3;
    }

    return true;
}

void five_gon(int first, int next, int sum, string ans, int* mark)
{
    if (ans.size() == 16 and next == first)
    {
        if (validString(ans))
            if (compare(mx, ans))
                mx = ans;

        return;
    }

    int to = sum - next;

    for (int i = 1; i < to; i++)
    {
        if (!mark[i] and !mark[sum - i - next])
        {
            int tmp[11];
            memcpy(tmp, mark, 11 * sizeof(int));
            tmp[i] = 1;
            tmp[sum - i - next] = 1;

            five_gon(first, i, sum, ans + to_string(sum - i - next) + to_string(next) + to_string(i), tmp);
        }
    }
}

int main()
{
    int mark[11] = { 0 };

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            for (int k = 1; k <= 10; k++)
            {
                if (i + j + k < 13 or i == j or i == k or j == k)
                    continue;

                mark[i] = mark[k] = 1;

                string tmp = to_string(i) + to_string(j) + to_string(k);

                five_gon(j, k, i + j + k, tmp, mark);

                memset(mark, 0, 11 * sizeof(int));
            }
        }
    }

    cout << mx << endl;

    return 0;
}