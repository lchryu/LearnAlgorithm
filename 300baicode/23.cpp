#include <bits/stdc++.h>

using namespace std;


int main() {
    //fastIO();
    int n; cin >> n;
    bool flag = false;
    // o(n) -> o(n / 3)
    // 3 6 9 12
    for (int i = 3; i <= n; i += 3) {
        cout << i << " ";
        flag = true;
    }
    if (!flag) cout << "-";
}