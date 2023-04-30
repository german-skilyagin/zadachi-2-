#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct Cell {
    int x, y, dist;
};

const int MAXN = 100;
const int INF = 1e9;
int n, m;
int maze[MAXN][MAXN];
int dist[MAXN][MAXN];
bool visited[MAXN][MAXN];
vector<pair<int, int>> teleporters;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool valid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m&& maze[x][y] != 1;
}

void bfs(int sx, int sy, int ex, int ey) {
    memset(visited, false, sizeof(visited));
    memset(dist, INF, sizeof(dist));
    queue<Cell> q;
    q.push({ sx, sy, 0 });
    visited[sx][sy] = true;
    dist[sx][sy] = 0;
    while (!q.empty()) {
        Cell cur = q.front();
        q.pop();
        int x = cur.x, y = cur.y, d = cur.dist;
        if (x == ex && y == ey) { cout << "Shortest path: " << d << endl; return; }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (valid(nx, ny) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                dist[nx][ny] = d + 1;
                if (maze[nx][ny] == 2) {
                    for (auto tp : teleporters) {
                        if (tp.first != nx || tp.second != ny) {
                            q.push({ tp.first, tp.second, d + 1 });
                            visited[tp.first][tp.second] = true;
                            dist[tp.first][tp.second] = d + 1;
                        }
                    }
                }
                else { q.push({ nx, ny, d + 1 }); }
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
            if (maze[i][j] == 2) { teleporters.push_back({ i, j }); }
            else if (maze[i][j] == 3) { sx = i; sy = j; }
            else if (maze[i][j] == 4) { ex = i; ey = j; }
        }
    }
    bfs(sx, sy, ex, ey);
    return 0;
}