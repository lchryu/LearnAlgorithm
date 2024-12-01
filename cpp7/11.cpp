#include <bits/stdc++.h>
using namespace std;
int main() {
    long long a, b;
    cin >> a >> b;
    long long c = pow(a, 3) - 3 * a * b + 3 * a * b * b - pow(b, 3);
    cout << c;
}

