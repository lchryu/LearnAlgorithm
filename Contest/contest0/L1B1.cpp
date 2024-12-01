#include <bits/stdc++.h>
using namespace std;
int main() {
    double a, b, c, x;
    cout << "Nhap a = "; cin >> a;    
    cout << "Nhap b = "; cin >> b;    
    cout << "Nhap c = "; cin >> c;    
    cout << "Nhap x = "; cin >> x;    

    double f = a * pow(x, 2) + b * x + c;

    cout << "f(" << x << ") = ";
    cout << a << "*" << x << "^2 + " << b << "*" << x << " + " << c << " = ";
    cout << f;
}