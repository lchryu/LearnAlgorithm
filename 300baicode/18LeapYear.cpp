#include <bits/stdc++.h>
using namespace std;
bool isLeapYear(int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}
int main() {
    int month, year, day; cin >> month >> year;
    switch (month)
    {
    case 1:case 3:case 5:case 7:case 8:case 10:case 12:
        day = 31;
        break;
    case 2:
        if (isLeapYear(year)) day = 29;
        else day = 28;
        break;
    default:
        day = 30;
        break;
    }
    cout << day;
}