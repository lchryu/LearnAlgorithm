#include <bits/stdc++.h>
#define ll long long
/**
 * @brief Calculates the sum of digits of a given integer.
 *
 * This function takes an integer as input and recursively calculates the sum of its digits.
 *
 * @param n The integer whose digits' sum is to be calculated.
 * @return The sum of the digits of the input integer.
 */
ll sumOfDigits(ll n) {
    if (n == 0) return 0;
    return n % 10 + sumOfDigits(n/10);
}
int main() {
    ll n; std::cin >> n;
    std::cout << sumOfDigits(n);
}