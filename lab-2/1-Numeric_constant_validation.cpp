#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;

    cout << "Enter a string to check if it is a numeric constant: ";
    cin >> s;

    bool flag = true;

    for (int i = 0; i < s.length(); i++) {
        if (i == 0 && s[i] == '-') 
            continue;  
        else if (s[i] == '.') 
            continue;  
        else if (s[i] >= '0' && s[i] <= '9') 
            continue;  
        else {
            flag = false;  
            break;
        }
    }

    if (flag) {
        cout << "Numeric constant\n";
    } else {
        cout << "Not numeric\n";
    }

    return 0;  
}
