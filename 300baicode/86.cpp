#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;

void fastIO() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
}

int main() {
    fastIO();
    double a, b, c; cin >> a >> b >> c;
    double perimeter = (a + b + c);
    double s = perimeter / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    cout << fixed << setprecision(1) << perimeter << ' ';
    cout << fixed << setprecision(3) << area << endl;
}