#include <bits/stdc++.h>
using namespace std;

int main() {
    char a[50], b[50];
    int x, y;

    cout << "Enter the size of first name: ";
    cin >> x;

    cout<<"Enter the first name: ";

    for (int i = 0; i < x; i++) {
        cin >> a[i];
    }
    a[x] = '\0';  // Add null-terminator to first name

    cout << "Enter the size of last name: ";
    cin >> y;
     cout<<"Enter the last name: ";

    for (int i = 0; i < y; i++) {
        cin >> b[i];
    }
    b[y] = '\0';  // Add null-terminator to last name

    cout << "Full name: " << a << " " << b << "\n";
}
