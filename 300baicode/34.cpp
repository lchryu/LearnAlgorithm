#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int main() {
    int l, r; cin >> l >> r;
    int ok = 0;
    for (int i = l; i <= r; i++) {
        if (isPrime(i)) {
            ok = 1;
            cout << i << " ";
        }
    }
    if (!ok) cout << "-";
}