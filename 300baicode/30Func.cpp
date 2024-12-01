#include <bits/stdc++.h>
using namespace std;
int tong_a_b(int l, int r) {
    int s = 0;
    for (int i = l; i <= r; i++) s += i;
    return s;
}
int main() {
    int a, b; cin >> a >> b;
    cout << tong_a_b(a, b);
}