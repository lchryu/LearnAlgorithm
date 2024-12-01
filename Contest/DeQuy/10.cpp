#include <bits/stdc++.h>
using namespace std;
using ll = long long;
double s(int n) {
    if (n == 1) return 1;
    return (double)1/n + s(n - 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    int n; cin >> n;
    cout << fixed << setprecision(3) << s(n);
}
