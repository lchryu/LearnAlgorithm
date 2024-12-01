#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int cnt35 = 0;
    for (int i = 3; i <= n; i++) {
        if (i % 3 == 0 || i % 5 == 0) cnt35 += i;
    }
    cout << cnt35;
}