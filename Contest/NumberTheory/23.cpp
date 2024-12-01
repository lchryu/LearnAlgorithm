#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll n; cin >> n;
    ll ans = 0;
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            ans += i;
            if (i != n / i) ans += n / i;
        }
    }
    cout << ans;
}