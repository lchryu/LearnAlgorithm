#include <iostream>
#define ll long long
const int MAX = 101;
ll memo[MAX][MAX];
using namespace std;
ll combination(ll n, ll k) {
    if (k == 0 || k == n) return 1;
    if (memo[n][k] != 0) return memo[n][k]; 
    memo[n][k] = combination(n - 1, k - 1) + combination(n - 1, k); 
    return memo[n][k];
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        ll n, k;
        std::cin >> n >> k;
        std::cout << combination(n, k) << std::endl;
    }
    return 0;
}
