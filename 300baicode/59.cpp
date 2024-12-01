#include <bits/stdc++.h>
#include <map>
#include <set>
#define ll long long
using namespace std;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a;
    map<ll, ll> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
        m[x]++;
    }
    /*
        2 - 2
        3 - 2
        10 - 1
    */
    pair<ll, ll> maxE = *m.begin();
    for (auto p : m)
    {
        if (p.second > maxE.second)
            maxE = p;
    }
    for (int i = 0; i < n; i++)
    {
        if (m[a[i]] == maxE.second)
        {
            cout << a[i] << ' ' << m[a[i]];
            break;
        }
    }
}