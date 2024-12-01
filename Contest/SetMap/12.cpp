#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> se1, uni, inter;
    while (n--) {
        int x;
        cin >> x;
        se1.insert(x);
        uni.insert(x);
    }
    while (m--) {
        int x;
        cin >> x;
        if (se1.count(x)) {
            inter.insert(x);
        }
        uni.insert(x);
    }
    for (int x : uni) {
        if (!inter.count(x)) {
            cout << x << " ";
        }
    }
    return 0;
}