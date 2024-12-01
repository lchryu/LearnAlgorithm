#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define ll long long
#define X first
#define Y second

using namespace std;

void fastIO() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
}

int main() {
    string s; cin >> s;
    int sum = 0;

    for (int i = 0; i < s.size(); i++) {
        string t = "";
        if (isdigit(s[i])) {
            for (int j = i; j < s.size(); j++) {
                if (isdigit(s[j])) t += s[j];
            }
        }
        if (t.size() > 0) sum += stoi(t);
    }
    cout << sum;
}