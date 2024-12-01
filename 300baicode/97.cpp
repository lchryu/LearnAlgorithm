#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, cnt = 0;
    while (cin >> x) {
        bool flag = true;
        if (x < 2) flag = false;
        for (int i = 2; i <= sqrt(x); ++i) {
            if (x % i == 0) flag = false;
        }
        if (flag) cnt++;
    }
    if (cnt == 0) cout << "-";
    else cout  << cnt;
}