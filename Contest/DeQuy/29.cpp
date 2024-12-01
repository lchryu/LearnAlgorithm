#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<int, ll>dict;

ll f(ll n){
    if (n < 3) return n;
    if (dict.find(n) != dict.end()) return dict[n];
    
    ll k = n / 3;
    ll res = f(2 * k);
    if (n % 3 > 0) res += f(2 * k + 1);
    if (n % 3 > 1) res += f(2 * k + 2);
    dict[n] = res;
    
    return res;
}

int main() {
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        cout << f(n) << endl;
    }
}
