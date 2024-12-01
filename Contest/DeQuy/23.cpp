#include <bits/stdc++.h>
using namespace std;

// Recursive function to check if all elements are even
bool checkEven(int arr[], int index, int n) {
    if (index == n) // Base case: If we've checked all elements
        return true;
    if (arr[index] % 2 != 0) // If any element is odd
        return false;
    return checkEven(arr, index + 1, n); // Recursive call to check the next element
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Check if the array contains only even numbers
    if (checkEven(arr, 0, n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
