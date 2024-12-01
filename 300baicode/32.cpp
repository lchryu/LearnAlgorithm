#include <bits/stdc++.h>
using namespace std;
int main() {
    int l, r; cin >> l >> r;
    int cnt35 = 0, cnt2 = 0;
    for (int i = l; i <= r; i++) {
        if (i % 3 == 0 || i % 5 == 0) cnt35++;
        if (i % 2 == 0) cnt2 += i;
    }
    cout << cnt35 << ' ' << cnt2;
}
