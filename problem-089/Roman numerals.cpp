#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string replaceFirstOccurrence(string& s, const string& toReplace, const string& replaceWith)
{
    size_t pos = s.find(toReplace);
    if (pos == string::npos) return s;

    return s.replace(pos, toReplace.length(), replaceWith);
}

int main()
{
    string replace[][6] = { {"DCCCC", "CM"},
                            {"CCCC",  "CD"},
                            {"LXXXX",  "XC"},
                            {"XXXX",  "XL"},
                            {"VIIII", "IX"},
                            {"IIII",  "IV"} };

    fstream file("roman.txt");
    string line;

    int res = 0;

    while (getline(file, line))
    {
        int size = line.size();

        for (int i = 0; i < 6; i++)
        {
            line = replaceFirstOccurrence(line, replace[i][0], replace[i][1]);
        }
        res += size - line.size();
    }

    cout << res << endl;

    return 0;
}