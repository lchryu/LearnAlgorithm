#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;

void fastIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
const int mod = 998244353;
ll cal(ll a)
{
    return a % mod / 2 * (a % mod + 1) % mod;
}
int main()
{
    fastIO();
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll a1 = cal(a), b1 = cal(b), c1 = cal(c);
        cout << (a1 * b1 % mod * c1 % mod) % mod << endl;
    }
    return 0;
}