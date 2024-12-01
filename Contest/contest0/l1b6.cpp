#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c;
    cout << "Nhap a = "; cin >> a;
    cout << "Nhap b = "; cin >> b;
    cout << "Nhap c = "; cin >> c;
    int y;
    if (b <= c) {
        y = pow(a, 2) + 3 * a - 1;
    } else {
        y = 0;
    }
    cout << "Y = " << y;
}