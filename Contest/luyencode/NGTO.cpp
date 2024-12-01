#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return n > 1;
}
int main() {
    int n; cin >> n;
    map<int, int>m;
    for (int i = 2; i <= n / 2; i++) {
        if (isPrime(i) and isPrime(n - i) and i != n - i) {
            m.insert({i, n - i});
        }
    }
    cout << m.size() << endl;
    for (auto x : m) {
        cout << x.first << " " << x.second << endl;
    }
}