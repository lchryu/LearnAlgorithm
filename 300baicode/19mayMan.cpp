#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n; cin >> n;
    int s = 0;
    while (n != 0) {
        s += n % 10;
        n /= 10;
    }
    s = s % 10;
    cout << s << endl;
    if (s == 9) cout << "may man";
    else cout << "chua may man";
}