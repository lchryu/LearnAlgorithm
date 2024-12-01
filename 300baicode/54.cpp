#include <bits/stdc++.h>
using namespace std;
vector<int>a;
int main() {
    int x;
    while (cin >> x) a.push_back(x);
    int res = INT_MIN;
    for (int x : a) {
        if (x < 0 && res < x) {
            res = x;
        }
    }
    if (res == INT_MIN) cout << "-";
    else cout << res << endl;
}