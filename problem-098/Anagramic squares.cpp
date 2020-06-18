#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

const int N = 20000;

string words[N + 1];

int mx = 0;

bool isAnagram(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;

    int anagram[26] = { 0 };

    for (unsigned int i = 0; i < s1.size(); i++)
        anagram[(int)s1[i] - 65]++;

    for (unsigned int i = 0; i < s2.size(); i++)
        anagram[(int)s2[i] - 65]--;

    for (int i = 0; i < 26; i++)
        if (anagram[i] != 0)
            return false;

    return true;
}

void maxSquareAnagram(string a, string b)
{
    int from = (int)ceil(sqrt(pow(10, a.size() - 1)));
    int to = (int)floor(sqrt(pow(10, a.size()) - 1));

    for (int i = from; i < to; i++)
    {
        int t[26] = { 0 };

        for (int i = 0; i < 26; i++)
            t[i] = -1;

        int tmp = i * i;
        int it = a.size() - 1;
        bool flag = false;

        while (tmp)
        {
            int k = t[(int)a[it] - 'A'];
            int m = tmp % 10;

            for (int j = 0; j < 26; j++)
            {
                if (t[j] == m)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
            else if (k == m or k == -1)
            {
                t[(int)a[it] - 'A'] = m;
            }
            else
            {
                flag = true;
                break;
            }

            tmp /= 10;
            it--;
        }

        int res = 0;

        if (!flag)
        {
            if (t[(int)b[0] - 'A'] == 0)
                continue;

            for (unsigned int j = 0; j < b.size(); j++)
                res = 10 * res + t[(int)b[j] - 'A'];

            if ((sqrt(res) - floor(sqrt(res))) == 0)
                mx = max(mx, max(res, i * i));
        }
    }
}

int main()
{
    ifstream file("words.txt");
    string line;

    if (!getline(file, line))
    {
        cout << "Something went wrong with reading file!\n";
        return -1;
    }

    unsigned int it = 0;
    int words_it = 0;

    string res = "";

    while (it < line.size())
    {
        if (line[it] == '"' or line[it] == ',')
        {
            if (res != "")
                words[words_it++] = res;

            res = "";
            it++;

            continue;
        }

        res += line[it++];
    }

    for (int i = 0; i < words_it; i++)
    {
        for (int j = i + 1; j < words_it; j++)
        {
            if (isAnagram(words[i], words[j]))
            {
                maxSquareAnagram(words[i], words[j]);
            }
        }
    }

    cout << mx << endl;

    return 0;
}