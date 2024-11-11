#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int optNum = 1;

    cout << "Enter a string to check for operators: ";
    cin >> s;

    bool flag = false;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '=') {
            flag = true;
            cout << "Operator " << optNum << ": " << s[i] << "\n";
            optNum++;
        }
    }

    if (!flag) {
        cout << "Operator not found\n";
    }

    return 0;
}
