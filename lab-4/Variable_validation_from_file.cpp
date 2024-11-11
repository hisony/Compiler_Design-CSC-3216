#include <iostream>
#include <string>
#include <fstream>
#include <set>

using namespace std;

bool isValidIdentifier(string variable, const set<string> &keywords)
{
    if (keywords.find(variable) != keywords.end())
    {
        cout << "Invalid: Variable name can't be the same as a keyword name\n";
        return false;
    }

    if (variable.empty())
    {
        cout << "Invalid: Variable name is empty.\n";
        return false;
    }

    if (!(variable[0] == '_' || (variable[0] >= 'a' && variable[0] <= 'z') ||
          (variable[0] >= 'A' && variable[0] <= 'Z')))
    {
        cout << "Invalid: Variable name starts with '" << variable[0] << "' which is invalid.\n";
        return false;
    }

    for (int i = 1; i < variable.size(); ++i)
    {
        if (!(variable[i] == '_' || (variable[i] >= 'a' && variable[i] <= 'z') ||
              (variable[i] >= 'A' && variable[i] <= 'Z') ||
              (variable[i] >= '0' && variable[i] <= '9')))
        {
            if (variable[i] == ' ')
            {
                cout << "Invalid: Space should not be included in the variable name.\n";
                return false;
            }

            cout << "Invalid: '" << variable[i] << "' should not be included in the variable name.\n";
            return false;
        }
    }

    cout << "Variable name is valid\n";
    return true;
}

int main()
{
    string var;

    // Read keywords from a text file
    ifstream keywordFile("keywords.txt");
    if (!keywordFile.is_open())
    {
        cout << "Failed to open keywords file." << endl;
        return 1;
    }

    set<string> keywords;
    string keyword;
    while (keywordFile >> keyword)
    {
        keywords.insert(keyword);
    }
    keywordFile.close();

    cout << "Enter a variable name: ";
    getline(cin, var);

    isValidIdentifier(var, keywords);

    return 0;
}
