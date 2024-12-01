#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<int>a(n);
    ll an = 0, binh = 0, sum = 0;
    ll ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n; i++) {
        an += a[i];
        binh = sum - an;
        ans = min(ans, abs(binh - an));
    }
    cout << ans;
}