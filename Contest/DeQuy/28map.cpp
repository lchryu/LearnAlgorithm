#include <iostream>
#include <map>
#define ll long long
using namespace std;
map<pair<ll, ll>, ll> memo; // Using a map to store computed values of combinations

ll combination(ll n, ll k) {
    if (k == 0 || k == n) return 1;
    
    pair<ll, ll> key = make_pair(n, k);
    
    if (memo.find(key) != memo.end()) // Check if the value has already been computed
        return memo[key];
    
    memo[key] = combination(n - 1, k - 1) + combination(n - 1, k); // Compute and store the result
    return memo[key];
}

int main() {
    int T; cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        cout << combination(n, k) << endl;
    }
    return 0;
}
