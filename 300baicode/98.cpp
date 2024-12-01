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
    vector<int>a;
    int n, s = 0, cnt = 0;
    while (cin >> n) {
        bool flag = true;
        if (n < 2) flag = false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) flag = false;
        }
        if (flag) {
            s += n;
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << "-";
        return 0;
    }
    cout<< fixed << setprecision(2) << 1.0 * s / cnt;
}