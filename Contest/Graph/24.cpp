#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;  // so luong dinh va canh

// Ham kiem tra xem do thi co phai la cay hay khong
bool treeCheck(vector<int> a[]) {
    if (n - 1 != m) return 0;  // Mot cay phai co dung n-1 canh

    int visited[1001] = {};  // Mang danh dau cac dinh da tham
    int parent[1001] = {};   // Mang luu cha cua cac dinh trong cay
    queue<int> q;
    q.push(1);               // Bat dau tu dinh 1
    visited[1] = 1;          // Danh dau dinh 1 da duoc tham

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        visited[x] = 1;      // Danh dau dinh x da tham

        for (int j : a[x]) {
            if (visited[j] == 0) {  // Neu dinh j chua duoc tham
                parent[j] = x;      // Dat x la cha cua j
                q.push(j);          // Dua j vao hang doi de tiep tuc duyet
                visited[j] = 1;     // Danh dau j da tham
            }
            // Neu dinh j da duoc tham va khong phai la cha cua x, thi do thi co chu trinh
            else if (visited[j] && parent[x] != j) {
                return 0;  // Khong phai la cay vi ton tai chu trinh
            }
        }
    }
    return 1;  // Do thi la cay
}

int main() {
    cin >> n >> m;
    vector<int> alist[1001];  // Danh sach ke cua do thi

    // Nhap cac canh cua do thi
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        alist[x].push_back(y);  // Them canh tu x toi y
        alist[y].push_back(x);  // Them canh tu y toi x (vi do thi vo huong)
    }

    // Kiem tra xem do thi co phai la cay hay khong
    cout << (int) treeCheck(alist) << endl;

    return 0;
}
