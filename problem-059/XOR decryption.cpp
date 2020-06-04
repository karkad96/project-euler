#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream file("cipher.txt");
    string line;

    if (!getline(file, line))
    {
        cout << "Something went wrong with reading file!\n";
        return -1;
    }

    vector<int> vect;

    stringstream ss(line);

    for (int i; ss >> i;) {
        vect.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }

    bool flag = false;

    int sum = 0;

    for (int i = 97; i <= 122 and !flag; i++)
    {
        for (int j = 97; j <= 122 and !flag; j++)
        {
            for (int k = 97; k <= 122 and !flag; k++)
            {
                vector <int> tmp;

                for (int it = 2; it < vect.size(); it += 3)
                {
                    tmp.push_back((vect[it - 2] ^ i));
                    tmp.push_back((vect[it - 1] ^ j));
                    tmp.push_back((vect[it] ^ k));
                }

                for (int it = 3; it < tmp.size() - 1; it++)
                    if (tmp[it - 3] == 32 and tmp[it - 2] == 116 and tmp[it - 1] == 104 and tmp[it] == 101 and tmp[it + 1] == 32)
                    {
                        flag = true;
                        break;
                    }

                if (flag)
                    for (int it = 0; it < tmp.size(); it++)
                        sum += tmp[it];
            }
        }
    }

    cout << sum << endl;

    return 0;
}