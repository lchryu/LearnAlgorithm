#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; getline(cin, s);
    stringstream ss(s);
    string w;
    int d = 0;
    while (ss >> w) d++;
    cout << d;
}