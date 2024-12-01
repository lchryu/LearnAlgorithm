#include <bits/stdc++.h>
using namespace std;
int dq(int n) {
    if (n == 1) return -1;
    if (n % 2 == 0) return n + dq(n - 1);
    return -n + dq(n - 1);
}
int main() {
    int n; cin >> n;
    cout << dq(n);
}