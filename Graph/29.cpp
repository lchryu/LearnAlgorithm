#include <bits/stdc++.h>
using namespace std;

int n, u, v, s, t;
int maze[1001][1001];  // Ma tran mo ta me cung
int d[1001][1001];  // d[i][j] la duong di ngan nhat tu o xuat phat den o (i, j)
int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};  // Cac huong di chuyen xung quanh (tuong ung voi 8 huong)
int dy[8] = {0, 1, 0, -1, -1, -1, 1, 1};  // Cac huong di chuyen y (tuong ung voi 8 huong)

int findway() {
    memset(d, -1, sizeof(d));  // Khoi tao tat ca cac o la chua di qua (dat khoang cach la -1)
    d[u][v] = 0;  // Dat o xuat phat (u, v) co khoang cach la 0
    maze[u][v] = 0;  // Danh dau o xuat phat da di qua
    queue<pair<int, int>> q;  // Hang doi cho BFS
    q.push({u, v});  // Day o xuat phat vao hang doi
    
    while (!q.empty()) {
        pair<int, int> x = q.front();
        q.pop();
        // Neu da tim duoc duong toi dich va khong the tot hon
        if (d[s][t] != -1 && d[x.first][x.second] >= d[s][t]) continue;  
        if (x.first == s && x.second == t) continue;  // Neu da toi dich thi bo qua
        
        for (int i = 0; i < 8; i++) {  // Duyet qua 8 huong
            int a = x.first + dx[i], b = x.second + dy[i];
            if (a > 0 && a <= n && b > 0 && b <= n && maze[a][b] == 1) {
                q.push({a, b});
                d[a][b] = d[x.first][x.second] + 1;  // Cap nhat khoang cach
                maze[a][b] = 0;  // Danh dau o da di qua
            }
        }
    }
    
    return d[s][t];  // Tra ve khoang cach den dich
}

int main() {
    cin >> n >> u >> v >> s >> t;  // Doc vao kich thuoc me cung va toa do diem xuat phat va dich
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> maze[i][j];  // Doc vao ma tran mo ta me cung
        }
    }

    int result = findway();  // Goi ham BFS de tim duong di ngan nhat
    cout << result << endl;  // In ra ket qua, neu khong co duong di se in ra -1
    
    return 0;
}
