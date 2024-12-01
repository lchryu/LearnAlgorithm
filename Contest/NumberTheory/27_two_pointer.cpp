#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool dn(ll n){
    string s = to_string(n);
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; 
        r--;
    }
    return true;
}
bool ptts(ll n){
    int cnt = 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            cnt++;
            while(n % i == 0){
                n /= i;
            }
        }
    }
    if(n != 1) cnt++;
    return cnt >= 3;
}
int main() {
    ll a, b; cin >> a >> b;
    for(int i = a; i <= b; i++){
        if(dn(i) && ptts(i)) cout << i << " ";
    }
    return 0;
}