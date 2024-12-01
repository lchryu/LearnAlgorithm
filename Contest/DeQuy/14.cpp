#include <bits/stdc++.h>
#define ll long long
int countDigits(int ll n) {
    if (n == 0) return 0;
    return 1 + countDigits(n / 10);
}
int main() {
    ll n; std::cin >> n;
    std::cout << countDigits(n);
}