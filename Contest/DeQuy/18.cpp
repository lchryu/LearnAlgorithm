#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll tongChan(ll n) {
    if (n == 0) return 0;
    int lastDigit = n % 10;
    if (lastDigit % 2 == 0) return lastDigit + tongChan(n/10);
    else return tongChan(n/10); 
}
ll tongLe(ll n) {
    if (n == 0) return 0;
    int lastDigit = n % 10;
    if (lastDigit % 2) return lastDigit + tongLe(n/10);
    else return tongLe(n/10); 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    ll n; cin >> n;
    cout << tongChan(n) << endl;
    cout << tongLe(n) << endl;
}
