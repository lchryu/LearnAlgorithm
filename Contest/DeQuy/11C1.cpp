#include <bits/stdc++.h>
using namespace std;
void dq(int n) {
    if (n == 0) return;
    dq(n / 2);
    if (n % 2 == 0) cout << 0;
    else cout << 1;
}
int main() {
    int n; cin >> n;
    if (n == 0) cout << 0;
    else dq(n);
}
