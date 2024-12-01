#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool isSquareNumber(int n) {
    int x = sqrt(n);
    return x * x == n;
}
int main() {
    int cnt = 0, s = 0;
    int x;
    while (cin >> x) {
        if(isSquareNumber(x)) {
            cnt++;
            s += x;
        }
    }
    if (cnt == 0) {
        cout << "-";
        return 0;
    }
    cout << fixed << setprecision(1) << 1.0 * s / cnt;
}