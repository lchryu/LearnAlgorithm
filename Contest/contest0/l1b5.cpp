#include <bits/stdc++.h>
using namespace std;
int main() {
    double mieng, mottiet, hocky;
    cout << "Diem Mieng = "; cin >> mieng;
    cout << "Diem Mot Tiet = "; cin >> mottiet;
    cout << "Diem Hoc Ky = "; cin >> hocky;

    
    double tb = (mieng + mottiet * 2 + hocky * 3) / 6;

    cout << "Diem TB = " << tb;
}