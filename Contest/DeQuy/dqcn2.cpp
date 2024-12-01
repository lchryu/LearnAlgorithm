#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<int, ll>dict;
int n;

ll g(int x) {
    if (x == 1 || x == 3) return x;
    if (dict.find(x) != dict.end()) return dict[x];
    ll res = 0;
    if (x % 2 == 0) res = g(x / 2);
    else {
        int n = x / 4;
        if (x % 4 == 1) res = 2 * g(2 * n + 1) - g(n);
        else res = 3 * g(2 * n + 1) - 2 * g(n);
    }
    
    dict[n] = res;
    return res;
}

int main() {
    cout << "Nhap n = "; cin >> n;
    cout << "g(" << n << ") = " << g(n);
    
}