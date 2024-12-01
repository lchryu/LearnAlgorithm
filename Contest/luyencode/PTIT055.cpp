#include <iostream>
#define ll long long
using namespace std;
int main() {
    ll n; cin >> n;
    for (ll i = 0; i <= 30; i++) {
        cout << n << " x " << i << " = " << n * i << endl;
    }
}
