#include <bits/stdc++.h>
using namespace std;
int main() {
    int seconds; cin >> seconds;
    int minutes = seconds / 60; seconds = seconds % 60;
    int hours   = minutes / 60; minutes %= 60;
    cout << hours << ":" << minutes << ":" << seconds;
}