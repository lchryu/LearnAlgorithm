// k so chinh phuong dau tien
#include <iostream>
#include <cmath>
using namespace std; 
bool cp(int i) {
    int x = sqrt(i);
    return x * x == i;
}
int main() {

    int k; cin >> k;
    int dem = 0;
    for (int i = 0; ; i++) { // 1 -> inf
        // check xem i co phai scp khong ?
        if (cp(i)) {
            cout << i << " ";
            dem++;
        }
        if (dem == k) break;
    }
    cout << endl;
}