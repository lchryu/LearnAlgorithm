#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    set<int> se;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (m--) {
        int x;
        cin >> x;
        se.insert(x);
    }
    for (int i = 0; i < n; i++) { // order appears
        if (se.count(a[i])) {
            se.erase(a[i]);
            cout << a[i] << " ";
        }
    }
    return 0;
}