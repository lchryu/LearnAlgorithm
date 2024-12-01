#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> se1, se2;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        se1.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        se2.insert(x);
    }
    for (int x : se1) {
        if (!se2.count(x)) {
            cout << x << " ";
        }
    }
    return 0;
}