#include <bits/stdc++.h>
using namespace std;
int main() {
    fastIO();
    string s; getline(cin, s);
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l++] != s[r--]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}