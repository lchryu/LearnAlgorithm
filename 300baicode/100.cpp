#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;

void fastIO() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
}

int main() {
    fastIO();
    int n; cin >> n;
    int a[n];
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    pair<int, int> minE = {a[0], 0}, maxE = minE;
    for (int i = 1; i < n; i++) {
        if (a[i] > maxE.first) maxE = {a[i], i};
        if (a[i] < minE.first) minE = {a[i], i};
    }
    cout << maxE.first << " " << maxE.second << endl;
    cout << minE.first << " " << minE.second << endl;
}