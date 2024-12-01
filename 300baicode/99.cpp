#include <bits/stdc++.h>
using namespace std;
bool p(int n) {
    if (n < 0) return false;
    int x = sqrt(n);
    return x * x == n;
}
int main() {
    int n; cin >> n;
    int s = 0, cnt = 0;
    while (cin >> n) {
        if (p(n)) {
            s += n;
            cnt++;
        }
    }
    //if (cnt == 0) cout << "-";
     cout << fixed << setprecision(1) << 1.0 * s / cnt;
}