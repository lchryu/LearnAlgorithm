#include <bits/stdc++.h>
using namespace std;

string multiply(string number, int multiplier) {
    string result = "";
    int carry = 0;
    for (int i = number.size() - 1; i >= 0; --i) {
        int product = (number[i] - '0') * multiplier + carry;
        carry = product / 10;
        result += (product % 10) + '0';
    }
    while (carry) {
        result += (carry % 10) + '0';
        carry /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    // string N = "100000000000000000000"; // 1e20
    // int T = 1000; // 1e3
    string N;
    int T;
    cin >> N >> T;
    string result = N;
    for (int i = 0; i < T; ++i) result = multiply(result, 2);

    cout << result << endl;

    return 0;
}