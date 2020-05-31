#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

const int N = 6000;

string names[N + 1];

int main()
{
    ifstream file("names.txt");
    string line;

    if (!getline(file, line))
    {
        cout << "Something went wrong with reading file!\n";
        return -1;
    }

    unsigned int it = 0;
    int names_it = 0;

    string res = "";

    while (it < line.size())
    {
        if (line[it] == '"' or line[it] == ',')
        {
            if (res != "")
                names[names_it++] = res;

            res = "";
            it++;

            continue;
        }

        res += line[it++];
    }

    sort(names, names + names_it);

    int total = 0;

    for (int i = 0; i < names_it; i++)
    {
        int score = 0;
        string tmp = names[i];

        for (unsigned int j = 0; j < tmp.size(); j++)
        {
            score += (int)tmp[j] - 64;
        }

        score *= (i + 1);
        total += score;
    }

    cout << total << endl;

    return 0;
}
