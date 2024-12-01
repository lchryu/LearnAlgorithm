#include <bits/stdc++.h>
#define ll long long
using namespace std;
pair<ll, ll> findMaxMinDigits(ll n) {
    if (n < 10) {
        return {n, n}; 
    } else {
        ll last_digit = n % 10;
        pair<ll, ll> result = findMaxMinDigits(n / 10);
        ll max_digit = max(last_digit, result.first);
        ll min_digit = min(last_digit, result.second);
        return {max_digit, min_digit};
    }
}

int main() {
    ll n; cin >> n;
    auto res = findMaxMinDigits(n);
    cout << res.first << ' ' << res.second;
    return 0;
}