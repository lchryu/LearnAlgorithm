#include <bits/stdc++.h>
using namespace std;

bool isTriangle(double a, double b, double c) {
    return (a + b > c) and (a + c > b) and (b + c > a);
}
int main() {
    double a, b, c; cin >> a >> b >> c;
    if (!isTriangle(a, b, c)) cout << "Day khong phai la 3 canh cua mot tam giac";
    else {
        cout << "Day la 3 canh cua mot tam giac\n";
        double perimeter = (a + b + c);
        double semiPerimeter = perimeter / 2;
        double area = sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c));
        cout << fixed << setprecision(2) << perimeter << ' ';
        cout << fixed << setprecision(1) << area << ' ';
    }
}