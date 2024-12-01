#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

#define ll long long
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

vector<ii>edges;
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);

    int v; cin >> v;
    cin.ignore();
    for (int i = 1; i <= v; i++) {
        string adjList; getline(cin, adjList);

        stringstream ss(adjList);
        string neighbor; // 3, 4, 5
        while (ss >> neighbor) {
            if (i < stoi(neighbor)) edges.pb({i, stoi(neighbor)}); // 3, 2
        }
    }
    for (ii p : edges) cout << p.fi << ' ' << p.se << "\n";
}
/*
                           _
                        _ooOoo_
                       o8888888o
                       88" . "88
                       (| -_- |)
                       O\  =  /O
                    ____/`---'\____
                  .'  \\|     |//  `.
                 /  \\|||  :  |||//  \
                /  _||||| -:- |||||_  \
                |   | \\\  -  /'| |   |
                | \_|  `\`---'//  |_/ |
                \  .-\__ `-. -'__/-.  /
              ___`. .'  /--.--\  `. .'___
           ."" '<  `.___\_<|>_/___.' _> \"".
          | | :  `- \`. ;`. _/; .'/ /  .' ; |
          \  \ `-.   \_\_`. _.'_/_/  -' _.' /
===========`-.`___`-.__\ \___  /__.-'_.'_.-'================
*/