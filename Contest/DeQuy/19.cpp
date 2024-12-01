#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(ll n) {
    if (n < 10) return n % 2 == 0;
    
    int lastDigit = n % 10;
    if (lastDigit % 2 == 1) return false;

    return check(n / 10);
}
int main() {
    ll n; cin >> n;
    if (check(n)) cout << "YES";
    else cout << "NO";
}
