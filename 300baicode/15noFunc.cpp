#include <bits/stdc++.h>

using namespace std;

/*
int: 1,2,3
string: "hello", "Vietnam"
bool: true, false
*/

int main() {
    double a, b, c; cin >> a >> b >> c;
    bool check;

    if (a + b > c && a + c > b && b + c > a) check = true;
    else check = false;
    
    
    if (check) {
        cout << "Day la 3 canh cua mot tam giac\n";
        double perimeter = (a + b + c);
        double semiPerimeter = perimeter / 2;
        double area = sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c));
        cout << fixed << setprecision(2) << perimeter << ' ';
        cout << fixed << setprecision(1) << area << ' ';
    } else {
        cout << "Day khong phai la 3 canh cua mot tam giac";
    }
}


