#include <bits/stdc++.h>
#define ll long long
using namespace std;

int pt(ll n) {
    int t = 1;
    for (int i = 2; i <= sqrt(n); ++i) {
        int cnt = 0;
        while (n % i == 0) {
            // cout << i << ' ';
            n /= i;
            cnt++;
        }
        t *= (cnt + 1);
    }
    if (n > 1) t *= 2;
    return t;
}
int main() {
    ll n; cin >> n;
    cout << pt(n);
}