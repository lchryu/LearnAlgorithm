#include <bits/stdc++.h>
#define ll long long
using namespace std;
int firstDigit(ll n) {
    if (n < 10) return n;
    return firstDigit(n / 10);
}
int main() {
    ll n; cin >> n;
    cout << firstDigit(n);
}