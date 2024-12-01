#include <bits/stdc++.h>
void Try(int n) {
    if (n > 1) Try(n / 2);
    std::cout << n % 2;
}
int main() {
    int n; std::cin >> n;
    if (n == 0) std::cout << 0;
    else Try(n);
}