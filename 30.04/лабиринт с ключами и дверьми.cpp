#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 1000;
const int INF = 1e9;
int n, m;
int maze[MAXN][MAXN];
int keys[MAXN];
bool visited[MAXN][MAXN][8];
int dist[MAXN][MAXN][8];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

struct State {
    int x, y, mask;
    State(int _x, int _y, int _mask) : x(_x), y(_y), mask(_mask) {}
};

bool valid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m&& maze[x][y] != 1;
}

void bfs(int sx, int sy, int ex, int ey) {
    queue<State> q;
    q.push(State(sx, sy, 0));
    visited[sx][sy][0] = true;
    dist[sx][sy][0] = 0;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int mask = q.front().mask;
        q.pop();
        if (x == ex && y == ey) { cout << "Shortest path: " << dist[x][y][mask] << endl; return; }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny)) {
                if (maze[nx][ny] >= 5 && maze[nx][ny] <= 7) {
                    int key = maze[nx][ny] - 5;
                    int new_mask = mask | (1 << key);
                    if (!visited[nx][ny][new_mask]) {
                        visited[nx][ny][new_mask] = true;
                        dist[nx][ny][new_mask] = dist[x][y][mask] + 1;
                        q.push(State(nx, ny, new_mask));
                    }
                }
                else if (maze[nx][ny] >= 2 && maze[nx][ny] <= 4) {
                    int door = maze[nx][ny] - 2;
                    if (mask & (1 << door)) {
                        if (!visited[nx][ny][mask]) {
                            visited[nx][ny][mask] = true;
                            dist[nx][ny][mask] = dist[x][y][mask] + 1;
                            q.push(State(nx, ny, mask));
                        }
                    }
                }
                else {
                    if (!visited[nx][ny][mask]) {
                        visited[nx][ny][mask] = true;
                        dist[nx][ny][mask] = dist[x][y][mask] + 1;
                        q.push(State(nx, ny, mask));
                    }
                }
            }
        }
    }
    cout << "No path found!" << endl;
}

int main() {
    cin >> n >> m;
    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 8) { sx = i; sy = j; }
            else if (maze[i][j] == 9) { ex = i; ey = j; }
        }
    }
    bfs(sx, sy, ex, ey);
    return 0;
}