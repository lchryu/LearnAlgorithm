#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
int main() {
    int n; cin >> n;
    int a[n];
    vector<int>evenNumbers;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) evenNumbers.pb(a[i]);
    }
    if (evenNumbers.empty()) cout << "0.00";
    else cout << fixed << setprecision(2) << accumulate(all(evenNumbers), 0.0)/evenNumbers.size();
}