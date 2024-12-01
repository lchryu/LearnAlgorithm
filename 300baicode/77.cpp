#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int>se;
    string s; getline(cin, s);
    for (auto x : s) se.insert(x); 
    cout << se.size();
}

