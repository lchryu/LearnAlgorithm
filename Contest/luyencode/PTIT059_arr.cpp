#include <bits/stdc++.h>
using namespace std;
const int m = 1e4;
int a[m + 1];
void chen(int a[], int&n, int k, int x) {
    n++;
    for (int i = n; i >= k + 1; i--) a[i] = a[i - 1];
    a[k] = x;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x; cin >> x;
    int k = n;
    for (int i = 0; i < n; i++) {
        if (x < a[i]) {
            k = i;
            break;
        }
    }
    chen(a, n, k, x);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}