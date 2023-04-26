#include <iostream>
using namespace std;

unsigned char A[820][821];
int d, mi, mj, n, m;
int visited;

inline bool valid(short x, short y) {
    return x >= 0 && x < m && y >= 0 && y < n && (A[x][y] & 0x7F) == '.';
}

void dfs(short x, short y, int dist) {
    if (!valid(x, y) || ((A[x][y] >> 7) != visited)) { return; }
    A[x][y] = (A[x][y] & 0x7F) | (~visited << 7);
    if (dist > d) { d = dist, mi = x, mj = y; }
    dfs(x - 1, y, ++dist); dfs(x + 1, y, dist); dfs(x, y - 1, dist); dfs(x, y + 1, dist);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) { cin >> A[i]; }
    int si = -1, sj = 0;
    for (int i = 0; i < m && si < 0; i++)
        for (int j = 0; j < n && si < 0; j++)
            if (A[i][j] == '.') { si = i, sj = j; }
    dfs(si, sj, 0);
    visited = 1;
    dfs(mi, mj, 0);
    cout <<  d;
}