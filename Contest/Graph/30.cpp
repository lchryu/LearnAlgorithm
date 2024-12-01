#include <bits/stdc++.h>
using namespace std;

int n, s, t, u, v;
int maze[1001][1001]; // Ban co luu gia tri 1 (co the di) hoac 0 (khong the di)
int d[1001][1001]; // Luu khoang cach tu diem bat dau den cac diem
int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1}; // Cac buoc di cua quan ma theo chieu x
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2}; // Cac buoc di cua quan ma theo chieu y

// Ham tim duong di ngan nhat bang BFS
int findWay() {
    if (maze[s][t] == 0) return -1; // Neu diem bat dau khong the di, tra ve -1

    memset(d, -1, sizeof(d)); // Dat tat ca gia tri trong mang d la -1
    d[u][v] = 0; // Khoi tao diem bat dau voi khoang cach 0
    queue<pair<int, int>> q; // Hang doi luu cac diem can duyet
    q.push({u, v}); // Dua diem bat dau vao hang doi
    maze[u][v] = 0; // Danh dau diem nay da duoc duyet

    // Bat dau duyet BFS
    while (!q.empty()) {
        pair<int, int> x = q.front(); // Lay phan tu dau tien trong hang doi
        q.pop(); // Xoa phan tu dau tien ra khoi hang doi

        // Duyet 8 huong di chuyen cua quan ma
        for (int i = 0; i < 8; i++) {
            int a = x.first + dx[i]; // Toa do moi theo chieu x
            int b = x.second + dy[i]; // Toa do moi theo chieu y

            // Kiem tra toa do moi co hop le va co the di khong
            if (a >= 0 && a < n && b >= 0 && b < n && maze[a][b] == 1) {
                maze[a][b] = 0; // Danh dau da di qua
                q.push({a, b}); // Them toa do moi vao hang doi
                d[a][b] = d[x.first][x.second] + 1; // Cap nhat khoang cach
            }
        }
    }

    // Neu khong the toi dich, tra ve -1
    if (d[s][t] == -1) return -1;
    
    return d[s][t]; // Tra ve khoang cach toi thieu
}

int main() {
    // Nhap kich thuoc ban co va cac toa do
    cin >> n >> u >> v >> s >> t;
    u--; v--; s--; t--; // Chuyen toa do ve dang chi so 0

    // Nhap ma tran ban co
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    // Tim duong va in ra ket qua
    cout << findWay() << endl;

    return 0;
}
