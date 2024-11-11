#include <bits/stdc++.h>
using namespace std;

int main()
{

    int size, arr[10], min = 1e6, max = 0;
    cout << "Enter the size of array :";
    cin >> size;

    for (int i = 0; i < size; i++)
    {

        cin >> arr[i];
        }

    for (int i = 0; i < size; i++)
    {

        if (arr[i] < min)
        {
            min = arr[i];
        }

        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    cout << "Minimum number :" << min << "\n";
    cout << "Maximum number :" << max << "\n";
}