#include <bits/stdc++.h>
using namespace std;
int main() {
    int month, year, day, check;
    cin >> month >> year;
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) check = 1;
    else check = 0;

    // 1: true, 0: false
    if (month == 2) {
        if (check == 1) day = 29;
        else day = 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) day = 30;
    else day = 31;

    cout << day;
} 
