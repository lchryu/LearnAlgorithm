// #include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return n > 1;
}
bool check(string&s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        swap(s[l++], s[r--]);
    }
    return isPrime(stoi(s));
}
int main() {
    int t; cin >> t;
    int ans = 0;
    for (int i = 1; i <= t; i++) {
        string x; cin >> x;
        if (check(x)) ans++;
    }
    cout << ans;
}