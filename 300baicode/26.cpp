#include <bits/stdc++.h>
using namespace std;
int main() {
    // O(n / 15)
    int n; cin >> n;
    int s = 0;
    for (int i = 15; i <= n; i += 15) {
        s += i;
    }
    cout << s;
}