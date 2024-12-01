#include <bits/stdc++.h>
using namespace std;

void leftToRight(int a[], int index, int n) {
    if (index == n) return;
    cout << a[index] << " ";
    leftToRight(a, index + 1, n);
}
void rightToLeft(int a[], int index, int n) {
    if (index < 0) return;
    cout << a[index] << " ";
    rightToLeft(a, index - 1, n);
}
int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    leftToRight(a, 0, n);
    cout << "\n";
    rightToLeft(a, n - 1, n);
    return 0;

}