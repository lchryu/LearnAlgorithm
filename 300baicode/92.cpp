#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;

void fastIO() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    system("cls");
}

int main() {
    int a, b, c; cin >> a >> b >> c;
    cout << a + b + c << ' ';
    cout << fixed << setprecision(2) << 1.0 * a / b + c << ' ';
    cout << fixed << setprecision(3) << 1.0 * a / (b + c) << ' ';
}