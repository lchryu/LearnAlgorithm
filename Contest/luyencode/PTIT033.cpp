#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, a, b;
    cin >> n >> a >> b;  // Nhập vào giá trị n, a, b

    // Kiểm tra các điều kiện
    bool chiaHetChoA = (n % a == 0);
    bool chiaHetChoB = (n % b == 0);

    if (chiaHetChoA && chiaHetChoB) {
        cout << "Co, tat ca!";
    } else if (chiaHetChoA) {
        cout << "Chi chia het cho " << a << ",";
    } else if (chiaHetChoB) {
        cout << "Chi chia het cho " << b << ".";
    } else {
        cout << "Khong chia het cho so nao ca.";
    }

    return 0;
}
