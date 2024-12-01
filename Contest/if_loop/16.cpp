#include <bits/stdc++.h>
#define ll long long
using namespace std;

int tong_cs(int n) {
    int sum = 0;
    while (n != 0) {
        int r = n % 10;
        sum += r;
        n /= 10;
    }
    return sum;
}

int main() {


    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        int n; cin >> n;
        cout << tong_cs(n) << endl;
    }
}