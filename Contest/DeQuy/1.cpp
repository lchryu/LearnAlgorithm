#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int gt(int n) {
    if (n == 0) return 1;
    return n * gt(n - 1);
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    int n; cin >> n;
    cout << gt(n);
}
