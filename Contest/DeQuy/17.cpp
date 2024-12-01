#include <bits/stdc++.h>
#define ll long long
using namespace std;
void rightToLeft(ll n){
    if (n < 10) cout << n << " ";
    else {
        cout << n % 10 << " ";
        rightToLeft(n / 10);
    }
}
void leftToRight(ll n) {
    if (n < 10) cout << n << " ";
    else {
        leftToRight(n / 10);
        cout << n % 10 << " ";
    }
}
int main() {
    ll n; cin >> n;
    leftToRight(n);
    cout << endl;
    rightToLeft(n);
}
