#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3;
int a[maxn + 5][maxn + 5], p[maxn + 5][maxn + 5];
int main() {
    int row, col; cin >> row >> col;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + a[i][j];
        }
    }
    int q; cin >> q;
    while (q--) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        cout << p[x2][y2] - p[x1 - 1][y2] - p[x2][y1 - 1] + p[x1 - 1][y1 - 1] << endl;
    }
}
