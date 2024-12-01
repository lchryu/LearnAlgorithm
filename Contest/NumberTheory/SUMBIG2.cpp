#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;
string addBigNums(string a, string b) {
    if (a.size() < b.size()) swap(a, b);
    reverse(all(a));
    reverse(all(b));
    int carry = 0;
    string res;
    for (int i = 0; i < a.size(); ++i) {
        int digitA = a[i] - '0';
        int digitB = i < b.size() ? b[i] - '0' : 0;
        int sum = digitA + digitB + carry;
        carry = sum / 10;
        res.push_back(sum % 10 + '0');
    }
    if (carry) res.push_back(carry + '0');
    reverse(all(res));
    return res;
}
int main() {
    int t; cin >> t;
    while (t--) {
        string a, b; cin >> a >> b;
        cout << addBigNums(a, b) << endl;
    }
}