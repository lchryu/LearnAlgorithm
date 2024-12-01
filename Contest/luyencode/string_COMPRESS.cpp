#include <bits/stdc++.h>
using namespace std;

string compress_string(string s) {
    int n = s.size();
    // loop over all possible divisors of the length of s
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            // check if s[0:i] repeated (n / i) times form s
            string t = s.substr(0, i);
            string repeated = "";
            for (int j = 0; j < n / i; j++) repeated += t;
            if (repeated == s) {
                if (n / i != 1) t = to_string(n / i) + t;
                return t;
            }
        }
    }
}

int main() {
    string s; cin >> s;
    cout << compress_string(s);
}