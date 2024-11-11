#include <bits/stdc++.h>
using namespace std;

bool isSingleline(string s) {
    if (s[0] == '/' && s[1] == '/'){
        return true;}
    return false;
}

bool isMultiLine(string s) {
    if (s[0] == '/' && s[1] == '*' && s[s.length() - 2] == '*' && s[s.length() - 1] == '/'){
        return true;}
    return false;
}

int main() {
    string s;

    cout << "Enter a line of code or comment: ";
    getline(cin, s);

    if (isSingleline(s))
        cout << "Single line comment detected\n";
    else if (isMultiLine(s))
        cout << "Multi line comment detected\n";
    else
        cout << "No comments line detected\n";

    return 0;
}
