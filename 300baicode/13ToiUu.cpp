#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    if (a == b and a == c) cout << "=";
    else cout << max(a, max(b, c));
    // don gian hon thi cout << max({a, b, c})
}
