#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int, int> m;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        if (m.find(a[i]) != m.end()) {
            cout << a[i] << ' ' << m[a[i]] << endl;
            m.erase(m.find(a[i]));
        }
    }
}