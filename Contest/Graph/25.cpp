#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;  // Maximum map size

// Movement directions: Right, Left, Down, Up
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// Global variables
int n, m;
char grid[MAXN][MAXN];  // Map grid

// DFS function to mark all cells in the same room
void DFS(int i, int j) {
    // Mark the current cell as a wall to avoid revisiting
    grid[i][j] = '#';

    // Explore the 4 neighboring cells
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];

        // If the neighboring cell is a floor and within map bounds, continue DFS
        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.') {
            DFS(x, y);
        }
    }
}

int main() {
    // Read map dimensions
    cin >> n >> m;

    // Read map data
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int room_count = 0;  // Variable to count the number of rooms

    // Traverse the entire map
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If a floor cell '.' is found, it indicates the start of a new room
            if (grid[i][j] == '.') {
                room_count++;  // Increment room count
                DFS(i, j);     // Perform DFS to mark the entire room
            }
        }
    }

    // Output the number of rooms
    cout << room_count << endl;
    return 0;
}
