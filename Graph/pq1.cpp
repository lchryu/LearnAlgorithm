#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int>a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int x : a) pq.push(x);

        ll ans = 0;

        while (pq.size() > 1) {
            long long top1 = pq.top();
            pq.pop();
            long long top2 = pq.top();
            pq.pop();
            ans += top1 + top2;
            pq.push(top1 + top2);
        }

        cout << ans << endl;
    }
}
/*
                           _
                        _ooOoo_
                       o8888888o
                       88" . "88
                       (| -_- |)
                       O\  =  /O
                    ____/`---'\____
                  .'  \\|     |//  `.
                 /  \\|||  :  |||//  \
                /  _||||| -:- |||||_  \
                |   | \\\  -  /'| |   |
                | \_|  `\`---'//  |_/ |
                \  .-\__ `-. -'__/-.  /
              ___`. .'  /--.--\  `. .'___
           ."" '<  `.___\_<|>_/___.' _> \"".
          | | :  `- \`. ;`. _/; .'/ /  .' ; |
  j        \  \ `-.   \_\_`. _.'_/_/  -' _.' /
===========`-.`___`-.__\ \___  /__.-'_.'_.-'================
*/