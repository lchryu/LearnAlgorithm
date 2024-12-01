#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;

int main()
{


    int n; cin >> n;
    int total = 0, km = 0; 
    if (n >= 31)
    {
        km = n - 30;
        total += km * 9000;
        n -= km;
    }
    if (n >= 2) // n = 1
    {
        km = n - 1;
        total += km * 10000;
        n -= km;
    }
    if (n >= 0)
        total += n * 12000;
    cout << total;
}