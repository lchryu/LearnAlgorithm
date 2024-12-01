#include <bits/stdc++.h>
using namespace std;
bool thuanNghich(int n) {
    string s = to_string(n);
    string ori = s;
    reverse(s.begin(), s.end());
    return ori == s;
}

bool _3nto(int n) {
    int ans = 0;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            ans++;
        }
    }
    if (n != 1) ++ans;
    return ans >= 3;
}

int main() {
    int a, b; cin >> a >> b;
    bool ok = false;
    for (int i = a; i <= b; ++i) {
        if (thuanNghich(i) && _3nto(i)) {
            ok = true;
            cout << i << " ";
        }
    }
    if (!ok) cout << -1;

}
