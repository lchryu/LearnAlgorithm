#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int ans = a[1] - a[0];
    for (int i = 1; i < n; i++) ans = min(ans, a[i] - a[i - 1]);
    cout << ans << endl;
    return 0;
}