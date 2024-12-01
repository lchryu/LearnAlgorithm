#include <bits/stdc++.h>
using namespace std;
const int m = 1e8;
bool p[m + 1] = {false, false}; // p[i]
void sieve() {
    for (int i = 2; i <= m; ++i) p[i] = true;
    for (int i = 2; i <= sqrt(m); i++) { // 2
        if (p[i]) {
            for (int j = i * i; j <= m; j += i) {
                p[j] = false;
            }
        }
    }
}
int main() {
    sieve();
    int n; cin >> n;
    for (int i = 0; i < n; ++i) if (p[i]) cout << i << ' ';
}

