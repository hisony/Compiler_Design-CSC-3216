#include <bits/stdc++.h>
using namespace std;

int main() {
    double n, x = 1;

    cout << "Enter the number for which you want to calculate the factorial:\n";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        x *= i;
    }

    cout << "Factorial of " << n << " is: " << x << "\n";
}
