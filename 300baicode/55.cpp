#include <bits/stdc++.h>
using namespace std;
int a[1000];
int main() {
    int n = 0;
    int x; 

    while (cin >> x) a[n++] = x;
    int max1 = INT_MIN, max2 = max1;
    for (int i = 0; i < n; i++) {
        if (a[i] > max1) {
            max2 = max1;
            max1 = a[i];
        } else if (a[i] > max2 ) max2 = a[i]; // ai <= max1
    }
    if (max2 == INT_MIN) cout << "-";
    else cout << max2 << endl;
}