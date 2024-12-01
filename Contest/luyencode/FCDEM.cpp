#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    int am = 0, duong = 0;
    while (n--) {
        std::string x; std::cin >> x;
        if (x[0] == '-') am++;
        else if (x != "0") duong++;
    }
    std::cout << am << " " << duong;
}