#include <iostream>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    int *a = new int[n], *b = new int[m], *res = new int[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    int i = 0, j = 0, index = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) i++;
        else {
            res[index++] = i;
            ++j;
        }
    }
    while (j < m) {
        res[index++] = i;
        j++;
    }
    for (int i = 0; i < m; i++) cout << res[i] << " ";
}