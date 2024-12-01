#include <bits/stdc++.h>
int gt(int n) {
    if (n == 0) return 1;
    return n * gt(n - 1);
}
int main() {
    int n; std::cin >> n;
    std::cout << gt(n);
}