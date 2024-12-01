#include <iostream>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    long long result = (a - b) * (a * a + a * b + b * b);
    cout << result << endl;
    return 0;
}