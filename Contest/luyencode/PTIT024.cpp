#include <bits/stdc++.h>
using namespace std;
const int m = 1e3 + 1;
vector<bool>is_prime(m, true);
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= m; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= m; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
int main() {
    sieve();
    string s; cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (is_prime[i]) {
            s[i] = '*';
        }
    }
    cout << s;
}