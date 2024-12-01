#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> pt(ll n) {
    vector<ll>v;
    for (int i = 2; i <= sqrt(n); ++i) {
        while (n % i == 0) {
            v.push_back(i);
            n /= i;
        }
    }
    if (n > 1) v.push_back(n);
    return v;
}
int main() {
    ll n; cin >> n;
    vector<ll>v = pt(n);
    for (int i = 0; i < v.size(); ++i) cout << v[i] << ' ';
}