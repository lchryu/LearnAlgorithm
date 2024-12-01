#include <bits/stdc++.h>
using namespace std;
void decimal_to_hexaDecimal(int n) {
    if (n != 0) {
        decimal_to_hexaDecimal(n/16);
        int r = n % 16;
        if (r < 10) cout << r;
        else cout << (char)(r + 55);
    }
}
int main() {
    int n; cin >> n;
    if (n == 0) cout << 0;
    else decimal_to_hexaDecimal(n);
}