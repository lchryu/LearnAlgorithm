#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;

void drawLine(int width) {
    for (int i = 0; i < width; ++i) {
        cout << '*';
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //int width = 7, height = 4; 
    int width, height; 
    cin >> width >> height;
    drawLine(width);

    for (int i = 0; i < height - 2; i++) {
        cout << "*";
        for (int j = 0; j < width - 2; j++) {
            cout << " ";
        }
        cout << "*";
        cout << endl;
    }

    drawLine(width);
    return 0;
}