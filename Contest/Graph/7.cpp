#include <bits/stdc++.h>
using namespace std;
int a[1001][1001];
vector<int>adj[1001];
int n;
int main() {
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        string adjList, num; getline(cin, adjList);
        
        stringstream ss(adjList);
        while (ss >> num) {
            a[i][stoi(num)] = 1; 
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
