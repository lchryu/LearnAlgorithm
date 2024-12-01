#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; getline(cin, s);
    string word;
    stringstream ss(s);
    while (ss >> word) cout << word << ' ';
}