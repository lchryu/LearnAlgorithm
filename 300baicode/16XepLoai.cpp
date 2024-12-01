#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;
    double avg = (a + b * 2) / 3;
    if (avg >= 8)
    {
        cout << fixed << setprecision(1) << avg << endl;
        cout << "Gioi";
    }
    else if (avg >= 6.5)
    {
        cout << fixed << setprecision(1) << avg << endl;
        cout << "Kha";
    }
    else if (avg >= 5.0)
    {
        cout << fixed << setprecision(1) << avg << endl;
        cout << "Trung binh";
    }
    else if (avg >= 3.5)
    {
        cout << fixed << setprecision(1) << avg << endl;
        cout << "Yeu";
    }
    else
    {
        cout << fixed << setprecision(1) << avg << endl;
        cout << "Kem";
    }
}