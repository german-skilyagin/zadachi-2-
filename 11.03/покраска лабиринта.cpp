#include<iostream>
using namespace std;

int w[55][55], d[55][55], used[55][55];
int x[4] = { 0, 0, 1, -1 };
int y[4] = { 1, -1, 0, 0 };
int ans = 0, n;

void dfs(int i, int j) {
    used[i][j] = 1;
    ans += d[i][j];

    for (int k = 0; k < 4; k++) {
        int u = i + x[k], v = j + y[k];
        if (u > 0 && u <= n && v > 0 && v <= n) {
            if (w[u][v] == 0 && used[u][v] == 0) dfs(u, v);
        }
    }
}

int main() {
    for (int i = 0; i < 55; i++) {
        for (int j = 0; j < 55; j++) {
            w[i][j] = 1;
            d[i][j] = 0;
            used[i][j] = 0;
        }
    }

    char c;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c;
            w[i][j] = (c == '#');
        }
    }

    w[0][1] = 0;
    w[1][0] = 0;
    w[n + 1][n] = 0;
    w[n][n + 1] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!w[i][j]) for (int k = 0; k < 4; k++) {
                int u = i + x[k], v = j + y[k];
                d[i][j] += w[u][v];
            }
        }
    }
    dfs(1, 1);
    if (!used[n][n]) dfs(n, n);

    cout << 25 * ans;
    return 0;
}