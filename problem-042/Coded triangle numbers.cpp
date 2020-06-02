#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int N = 2000;
string words[N + 1];

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

    int count = 0;

    for (int i = 0; i < words_it; i++)
    {
        string tmp = words[i];
        int score = 0;

        for (int j = 0; j < tmp.size(); j++)
        {
            score += (int)tmp[j] - 64;
        }

        double m = (sqrt(8 * score + 1) - 1) / 2;

        if (m == (int)m)
            count++;
    }

    cout << count << endl;

    return 0;
}