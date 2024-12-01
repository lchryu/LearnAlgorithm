#include <bits/stdc++.h>
using namespace std;

void gen(int n, string cur) {
    if ((int)cur.size() == n) {  // Ép kiểu cur.size() thành int để so sánh với n
        cout << cur << endl;
        return;
    }
    gen(n, cur + "0");
    gen(n, cur + "1");
}

int main() {
    int n; 
    cin >> n;
    gen(n, "");
    return 0;
}
