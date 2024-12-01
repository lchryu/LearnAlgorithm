#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool check(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}
int main() {
    int t; cin >> t;
    while (t--) {
        string s; ll k; cin >> s >> k;
        if (check(s)) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}
