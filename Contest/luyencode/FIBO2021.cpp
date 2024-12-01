#include <iostream>
using namespace std;

const int MOD = 2021;

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    
  
    int F1 = a % MOD;
    int F2 = b % MOD;
    int Fn;
    for (int i = 3; i <= n; i++) {
        Fn = (F1 + F2) % MOD;
        F1 = F2;
        F2 = Fn;
    }
    cout << Fn << '\n';
 

    return 0;
}
