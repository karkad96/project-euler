#include <iostream>
#include <vector>

using namespace std;

vector<int> cube;

void generateCubes(int n, int s, int depth)
{
    if (depth == 6)
        cube.push_back(s);

    for (int i = n; i < 10 and depth < 6; i++)
    {
        generateCubes(i + 1, s | (1 << i), depth + 1);
    }
}

int check(int a, int b, int c, int d)
{
    if (!((a & 1 << c) and (b & 1 << d)) and !((b & 1 << c) and (a & 1 << d)))
        return 0;

    return 1;
}

int main()
{
    generateCubes(0, 0, 0);

    int count = 0;

    for (unsigned int i = 0; i < cube.size(); i++)
    {
        for (unsigned int j = i + 1; j < cube.size(); j++)
        {
            if (!check(cube[i], cube[j], 0, 1))
                continue;
            if (!check(cube[i], cube[j], 0, 4))
                continue;
            if (!check(cube[i], cube[j], 0, 9) and !check(cube[i], cube[j], 0, 6))
                continue;
            if (!check(cube[i], cube[j], 1, 6) and !check(cube[i], cube[j], 1, 9))
                continue;
            if (!check(cube[i], cube[j], 2, 5))
                continue;
            if (!check(cube[i], cube[j], 3, 6) and !check(cube[i], cube[j], 3, 9))
                continue;
            if (!check(cube[i], cube[j], 4, 9) and !check(cube[i], cube[j], 4, 6))
                continue;
            if (!check(cube[i], cube[j], 6, 4) and !check(cube[i], cube[j], 9, 4))
                continue;
            if (!check(cube[i], cube[j], 8, 1))
                continue;

            count++;
        }
    }

    cout << count << endl;

    return 0;
}