#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define ll long long
#define X first
#define Y second

using namespace std;

void fastIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
int a[51][51];
int main()
{
    fastIO();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i == j || j == 0)
                a[i][j] = 1;
            else
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            if (a[i][j] != 0)
                cout << a[i][j] << " ";
        }
        cout << endl;
    }
}