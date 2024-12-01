#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; getline(cin, s);
    while (s[0] == ' ') s.erase(0, 1);
    cout << s;
}