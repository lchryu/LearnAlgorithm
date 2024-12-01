#include <iostream>
using namespace std;
int main() {
	int t; cin >> t;
	if (t > 0 && t <= 11) cout << "Thieu nhi";
	else if (t > 11 && t <= 25) cout << "Thieu nien";
	else if (t > 25 && t <= 50) cout << "Trung nien";
	else cout << "Lao nien";
}
