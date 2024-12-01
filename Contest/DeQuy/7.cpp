// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// ll tohop(int k, int n) {
//     if (k > n - k) k = n - k;
//     if (k == 0) return 1;
//     return tohop(k - 1, n - 1) + tohop(k, n - 1); 
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr); 
//     int k, n; cin >> k >> n;
//     cout << tohop(k , n);
// }
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll tohop(int k, int n) {
    if (k == 0 || k == n) return 1;
    return tohop(k - 1, n - 1) + tohop(k, n - 1); 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    int k, n; cin >> k >> n;
    cout << tohop(k , n);
}
