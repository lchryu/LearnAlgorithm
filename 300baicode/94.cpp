#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
void simplify(int& ts, int& ms) {
    int divisor = gcd(ts, ms);
    ts   /= divisor;
    ms /= divisor;
    if (ms < 0) {
        ts   *= -1;
        ms *= -1;
    }
}
void output(int ts, int ms) {
    simplify(ts, ms);
    if (abs(ts) > ms) {
        cout << ts / ms << "," << ts % ms << "/" << ms;
    }
    else cout << ts << "/" << ms;
    cout << endl;
}
void add(int t1, int m1, int t2, int m2) {
    int ts = t1 * m2 + t2 * m1;
    int ms = m1 * m2;
    output(ts, ms);
}
void subtract(int t1, int m1, int t2, int m2) {
    int ts = t1 * m2 - t2 * m1;
    int ms = m1 * m2;
    output(ts, ms);
}
void divide(int t1, int m1, int t2, int m2) {
    int ts = t1 * m2;
    int ms = m1 * t2;
    output(ts, ms);
}
void multiply(int t1, int m1, int t2, int m2) {
    int ts = t1 * t2;
    int ms = m1 * m2;
    output(ts, ms);
}
int main() {
#ifndef ONLINE_JUDGE
    FILE* file_in;
    freopen_s(&file_in, "input.txt", "r", stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a, b, c, d; cin >> a >> b >> c >> d;
    add(a, b, c, d);
    subtract(a, b, c, d);
    multiply(a, b, c, d);
    divide(a, b, c, d);
}