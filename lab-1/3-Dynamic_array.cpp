//First and Last Name Concatenation

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    
    cout << "Enter the size of the character arrays: ";
    cin >> n;

 
    char *a = new char[n];
    char *b = new char[n];

  
    cout << "Enter " << n << " characters for the first array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

   
    cout << "Enter " << n << " characters for the second array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

   
    cout << "\nArray 1: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }

    cout << "\nArray 2: ";
    for (int i = 0; i < n; i++) {
        cout << b[i] << ' ';
    }

    cout << "\n";


    delete[] a;
    delete[] b;
}
