#include <bits/stdc++.h>
using namespace std;
int a[51][51];
int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == j || j == 0) a[i][j] = 1;
            else a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            if (a[i][j] != 0) cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
