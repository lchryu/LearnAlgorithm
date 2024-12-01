#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define ll long long

using namespace std;

string add(string a, string b) {
    if (a.size() < b.size()) swap(a, b);
    reverse(all(a));
    reverse(all(b));
    int carry = 0;
    string result;
    for (size_t i = 0; i < a.size(); i++) {
        int digitA = a[i] - '0';
        int digitB = i < b.size() ? b[i] - '0' : 0;
        int sum = digitA + digitB + carry;
        carry = sum / 10;
        result.push_back(sum % 10 + '0');
    }
    if (carry > 0) result.push_back(carry + '0');
    reverse(all(result));
    return result;
}
const int MAXN = 1e4 + 1;
string f[MAXN] = {"0", "1", "1"};
int main() {
    // fastIO();
    for (int i = 3; i <= 10000; i++) {
        f[i] = add(f[i - 1], f[i - 2]);
    }
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        cout << f[n] << '\n';
    }
}
