#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int tmp;
    set<int>pNumber;
    while (cin >> tmp) {
        pNumber.insert(tmp);
    }
    if (pNumber.size() < 3) cout << "-";
    else {
        auto it = pNumber.begin();
        it++; it++;
        cout << *it;
    }
}