#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dq(ll n) {
    if (n == 0) return 0;
    return n * n * n + dq(n - 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    cout << dq(n);
}
