#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    cout << "Mua ";
    string season;
    if (2 <= n and n <= 4) season = "Xuan";
    else if (5 <= n and n <= 7) season = "Ha";
    else if (8 <= n and n <= 10) season = "Thu";
    else season = "Dong";
    cout << season;
}