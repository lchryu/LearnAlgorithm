#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000007;
int t[maxn];

// Sieve of Eratosthenes to mark non-prime numbers
void sieve() {
    t[0] = t[1] = 1;
    for (int i = 2; i <= sqrt(maxn); i++) {
        if (t[i] == 0) {
            for (int j = i * i; j <= maxn; j += i) {
                t[j] = 1;
            }
        }
    }
}

// Function to check if the last digit of the number is the largest
bool check(int n) {
    string s = to_string(n);
    char Max = *s.rbegin(); // Get the last digit
    
    for (int i = 0; i < s.size() - 1; i++) {
        if (Max < s[i]) return false;
    }
    return true;
}

int main() {
    sieve(); // Call sieve to mark all primes up to maxn
    int n; cin >> n;
    int ans = 0;
    
    for (int i = 2; i <= n; i++) {
        if (t[i] == 0 && check(i)) { // If i is prime and passes the check
            cout << i << " ";
            ans++;
        }
    }
    cout << endl << ans;
}
