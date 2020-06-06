#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

struct polygon
{
    int num;
    int kind;

    bool operator< (polygon const& other) const
    {
        return num < other.num;
    }

    bool operator==(const polygon& other)
    {
        return num == other.num and kind == other.kind;
    }
};

map<polygon, set<polygon>> m;
vector<vector<polygon>> v(6);
map<polygon, bool> visited;

void findPairs(int i, int j)
{
    for (unsigned int a = 0; a < v[i].size(); a++)
    {
        for (unsigned int b = 0; b < v[j].size(); b++)
        {
            if (v[i][a].num % 100 == v[j][b].num / 100)
            {
                m[v[i][a]].insert(v[j][b]);
            }
        }
    }
}

bool flag = true;

void dfs(polygon next, int* mark)
{
    if (mark[0] and mark[1] and mark[2] and mark[3] and mark[4] and mark[5])
    {
        if (flag and next.num % 100 == mark[3] / 100)
        {
            flag = false;
            int sum = 0;

            for (int i = 0; i < 6; i++)
                sum += mark[i];

            cout << sum << endl;
        }

        return;
    }

    for (auto s : m[next])
    {
        if (!mark[s.kind] and visited.find(s) == visited.end())
        {
            int tmp[6];
            memcpy(tmp, mark, 6 * sizeof(int));
            tmp[s.kind] = s.num;
            dfs(s, tmp);
        }
    }

    return;
}

int main()
{
    //45 - 140 triangular
    //32 - 99 square
    //26 - 81 pentagonal
    //23 - 70 hexagonal
    //21 - 63 heptagonal
    //19 - 58 octagonal

    int tr = 1;

    for (int n = 45; n <= 140; n++)
        v[0].push_back({ n * (n + 1) / 2, 0 });

    for (int n = 32; n <= 99; n++)
        v[1].push_back({ n * n, 1 });

    for (int n = 26; n <= 81; n++)
        v[2].push_back({ n * (3 * n - 1) / 2, 2 });

    for (int n = 23; n <= 70; n++)
        v[3].push_back({ n * (2 * n - 1), 3 });

    for (int n = 21; n <= 63; n++)
        v[4].push_back({ n * (5 * n - 3) / 2, 4 });

    for (int n = 19; n <= 58; n++)
        v[5].push_back({ n * (3 * n - 2), 5 });

    for (unsigned int i = 0; i < v.size(); i++)
    {
        for (unsigned int j = 0; j < v.size(); j++)
        {
            if (i == j)
                continue;

            findPairs(i, j);
        }
    }

    int mark[6] = { 0 };

    for (auto i : m)
    {
        dfs(i.first, mark);
        memset(mark, 0, 6 * sizeof(int));
    }

    return 0;
}