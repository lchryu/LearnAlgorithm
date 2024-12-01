#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

set<ll>v;  // Vector to store perfect numbers

bool check(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) 
            return false;
    }
    return n > 1;
}

void sinhHoanHao() {
    for (int p = 1; p <= 32; p++) {
        if (check(p)) {  // Check if p is prime
            ll tmp = pow(2, p) - 1;  // Mersenne prime candidate
            if (check(tmp)) {  // Check if 2^p - 1 is prime
                ll res = tmp * pow(2, p - 1);  // Generate perfect number
                v.insert(res);  // Add perfect number to the vector
            }
        }
    }
}

int main() {
    sinhHoanHao();  // Generate perfect numbers
    ll n;
    cin >> n;
    if (v.count(n)) cout << "YES";
    else cout << "NO";
}
