#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n; cin >> n;
    ll tmp = sqrt(n);
    if (tmp * tmp == n) cout << "YES";
    else  cout << "NO";
    return 0;
}
