#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    string s; getline(cin, s);
    char c; cin >> c;
    int index = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            index = i;
            break;
        }
    }
    cout << index;
}