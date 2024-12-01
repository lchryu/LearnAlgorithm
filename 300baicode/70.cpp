#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; getline(cin, s);
    s[0] = toupper(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] == ' ') s[i] = toupper(s[i]);
    }
    cout << s;
}