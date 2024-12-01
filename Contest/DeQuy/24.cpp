#include <bits/stdc++.h>
using namespace std;

// Recursive function to check if the array is strictly increasing
bool isIncreasing(int arr[], int index, int n) {
    if (index == n - 1) // Base case: If we've reached the last element
        return true;
    if (arr[index] >= arr[index + 1]) // If the current element is not less than the next one
        return false;
    return isIncreasing(arr, index + 1, n); // Recursive call to check the next pair
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (isIncreasing(arr, 0, n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
