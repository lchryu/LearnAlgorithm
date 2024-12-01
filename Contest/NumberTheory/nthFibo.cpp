#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll a[93] = {0, 1};
int main() {
    for (int i = 2; i <= 92; i++) a[i] = a[i - 1] + a[i - 2];
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << a[n] << endl;
    }
    return 0;
}
