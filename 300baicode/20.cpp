#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    int n; cin >> n;
    cout << n / 5000 << ' '; n %= 5000;
    cout << n / 2000 << ' '; n %= 2000;
    cout << n / 1000 << ' '; n %= 1000;
}