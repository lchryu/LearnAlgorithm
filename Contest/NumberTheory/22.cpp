#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a, b;
    cin >> a >> b;
    ll y = sqrt(b);
    ll x = ceil(sqrt(a));
    cout << y - x + 1;
}
