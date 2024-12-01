#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    set<int> se;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        se.insert(a[i]);
    }

    for (int i = 0; i < n; i++) { // duyet de lay ra thu tu xuat hien
        if (se.count(a[i])) { // note
            cout << a[i] << " ";
            se.erase(a[i]); // xoa ra khoi note
        }
    }
    return 0;
}