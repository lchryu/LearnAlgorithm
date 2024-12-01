#include <bits/stdc++.h>
using namespace std;
void Try(int n) {
    if (n > 15) Try(n / 16);
    int r = n % 16;
    if (r < 10) cout << r;
    else cout << (char)(r + 55);
}

int main() {
    int n; cin >> n;
    if (n == 0) cout << 0;
    else Try(n);
}