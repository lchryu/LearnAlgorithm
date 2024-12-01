#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll ans = 1;
    
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                ++cnt;
                n /= i;
            }
            ans *= (cnt + 1);  // Multiply the current divisor count
        }
    }

    // If there's a prime factor greater than sqrt(n), multiply by 2
    if (n != 1) {
        ans *= 2;
    }

    cout << ans;
}
