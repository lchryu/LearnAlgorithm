#include <iostream>
#include <cmath>  // Include cmath for sqrt()
using namespace std;
typedef long long ll;

int main() {
    ll a, b;
    cin >> a >> b;

    // Starting from the square root of 'a', going until the square root of 'b'
    for (ll i = ceil(sqrt(a)); i <= floor(sqrt(b)); i++) {
        ll tmp = i * i;
        if (tmp >= a && tmp <= b) {
            cout << tmp << " ";
        }
    }
    return 0;
}
