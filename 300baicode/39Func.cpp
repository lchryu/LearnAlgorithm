#include <bits/stdc++.h>
using namespace std;
bool cp(int n) {
    int x = sqrt(n);
    return x * x == n;
}
int main() {
    int n; cin >> n;
    if (cp(n)) cout << "Yes";
    else cout << "No";
}