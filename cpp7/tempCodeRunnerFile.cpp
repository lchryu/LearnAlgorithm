#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; cin >> n;
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s = s + i;
    }
    cout << s;
}