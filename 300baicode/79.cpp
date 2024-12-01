#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;

void fastIO()
{
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\lchry\\CLionProjects\\untitled\\input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    //fastIO();
    string s;
    getline(cin, s);
    for (char &c : s) c = tolower(c);
    map<char, int> m;Tran Phi An Binh
n
    for (char c : s)
    {
        if (c != ' ')
            m[c]++;
    }
    pair<char, int> maxE = *m.begin();
    for (auto p : m)
    {
        if (p.second > maxE.second)
            maxE = p;
    }
    for (auto c : s) {
        if (m[c] == maxE.second) {
            cout << c << ":" << m[c];
            break;
        }
    }
}