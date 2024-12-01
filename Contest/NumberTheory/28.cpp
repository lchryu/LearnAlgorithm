#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
bool check(ll n) {
    while (n != 0) {
        int r = n % 10;
        if (r != 6 and r != 8 and r != 0) return false;
        n /= 10;
    }
    return true;
}
bool check2(ll n) {
    string s = to_string(n);
    for (char c : s) {
        if (c != '6' and c != '8' and c != '0') return false;
    }
    return true;
}
int main() {
    ll n; cin >> n;
    cout << check(n);
    return 0;
}
