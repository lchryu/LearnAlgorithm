#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; getline(cin, s);
    for (auto &c : s) c = tolower(c);
    map<char,int>m;
    for (auto c : s) m[c]++;

    for (auto c : s) {
        if (m.find(c) != m.end()) {
            cout << c << ':' << m[c] << ' ';
            m.erase(c);
        }
    }
}