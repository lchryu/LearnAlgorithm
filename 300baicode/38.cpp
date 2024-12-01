#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    
    for (int i = 2; ; i++) {
        if (isPrime(i)) {
            cnt++;
            cout << i << " ";
        }
        if (cnt == n) break;
    }
    
    return 0;
}