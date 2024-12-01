#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    string s = to_string(n);
    map<char, int> mp;

    // Count occurrences of prime digits
    for (char x : s) {
        if (x == '2' || x == '3' || x == '5' || x == '7') {
            mp[x]++;
        }
    }

    // Print prime digits in ascending order of digits
    for (auto x : mp) {
        cout << x.first << " " << x.second << endl;
    }

    cout << endl;

    // Print prime digits in the order they appeared in n
    for (char x : s) {
        if (mp[x] != 0) {
            cout << x << " " << mp[x] << endl;
            mp[x] = 0;  // Reset to avoid printing duplicates
        }
    }
}
