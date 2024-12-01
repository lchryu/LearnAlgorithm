#include <bits/stdc++.h>
using namespace std;
int main() {
    int x;
    set<int>se;
    while (cin >> x) {
        se.insert(x);
    }
    cout << se.size() << endl;
}