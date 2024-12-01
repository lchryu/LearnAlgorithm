#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    cin.ignore();
    vector<pair<int, int>>v;
    int cnt = 1;
    while (n--) {
        string s; getline(cin, s);
        stringstream ss(s);
        string tmp;
        while (ss >> tmp) {
            int x = stoi(tmp);
            if (x > cnt) v.push_back({cnt, x});
        }
        cnt++;
    }
    sort(v.begin(), v.end());
    for (auto x : v) cout << x.first << ' ' << x.second << endl;
    return 0;
}
