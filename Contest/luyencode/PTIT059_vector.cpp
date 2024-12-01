#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int x; cin >> x;
    int k = 0;
    while (k < n and a[k] < x) k++;
    a.insert(a.begin() + k, x);
    for (int x : a) cout << x << " ";
}