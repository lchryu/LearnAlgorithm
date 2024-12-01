#include <bits/stdc++.h>
using namespace std;
int dq(int n) {
    if (n == 1) return 0;
    int res1 = 1e9, res2 = 1e9, res3 = 1e9;
    if (n % 2 == 0) res1 = 1 + dq(n / 2);
    if (n % 3 == 0) res2 = 1 + dq(n / 3);
    if (n > 1) res3 = 1 + dq(n - 1);
    return min({res1, res2, res3});
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    int n; cin >> n;
    cout << dq(n);
}
