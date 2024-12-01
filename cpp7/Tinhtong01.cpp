#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int s = 0;
    for (int i = n; i >= 1; i--) s += i;
    cout << s;
}