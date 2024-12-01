#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;
string addBigNums(string a, string b) {
    if (a.length() < b.length()) swap(a, b);
    reverse(all(a));
    reverse(all(b));

    string result;
    int carry = 0;

    for (size_t i = 0; i < a.length(); ++i) {
        int digitA = a[i] - '0';
        int digitB = (i < b.length()) ? b[i] - '0' : 0;

        int sum = digitA + digitB + carry;
        carry = sum / 10;
        result.push_back(sum % 10 + '0');
    }
    if (carry) result.push_back(carry + '0');

    reverse(all(result));
    return result;
}
int main() {
    string a, b; cin >> a >> b;
    cout << addBigNums(a, b);
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
          \  \ `-.   \_\_`. _.'_/_/  -' _.' /
===========`-.`___`-.__\ \___  /__.-'_.'_.-'================
*/