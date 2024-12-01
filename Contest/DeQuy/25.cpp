#include <bits/stdc++.h>
using namespace std;
int check(int a[], int l, int r, int x) {
    if (l > r) return 0;
    int m = (l + r)/2;
    if (a[m] == x) return 1;
    else if (a[m] < x) return check(a, 0, m - 1, x);
    else return check(a, m + 1, r, x);
}
int main() {
    int n; cin >> n;
    int a[n];    
    for (int i = 0; i < n; ++i) cin >> a[i];
    int x; cin >> x;
    cout << check(a, 0, n - 1, x);
}