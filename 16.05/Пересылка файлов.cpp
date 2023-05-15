#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int INF = 1e9;
const int MAXN = 22, MAXM = 22;

int n, m;
int d[MAXN][MAXN];
int p[MAXN][MAXN];
vector<int> path[MAXN][MAXN];

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[i][k];
                }
            }
        }
    }
}

void build_path(int s, int t) {
    if (p[s][t] == -1) {
        path[s][t].push_back(s);
        path[s][t].push_back(t);
    }
    else {
        build_path(s, p[s][t]);
        build_path(p[s][t], t);
        for (int i = 0; i < path[s][p[s][t]].size() - 1; i++) {
            path[s][t].push_back(path[s][p[s][t]][i]);
        }
        for (int i = 1; i < path[p[s][t]][t].size(); i++) {
            path[s][t].push_back(path[p[s][t]][t][i]);
        }
    }
}

int main() {
    cin >> n >> m;
    memset(d, INF, sizeof(d));
    memset(p, -1, sizeof(p));
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        d[u][v] = c;
    }
    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }
    floyd();
    int min_cost = INF, min_cnt = INF, min_mask = 0;
    for (int mask = 0; mask < (1 << m); mask++) {
        int cost = 0, cnt = 0;
        for (int i = 2; i <= n; i++) {
            int u = 1, v = i;
            for (int j = 0; j < path[u][v].size() - 1; j++) {
                int e = path[u][v][j];
                if (e > 0 && (mask & (1 << (e - 1)))) {
                    cost += d[path[u][v][j]][path[u][v][j + 1]];
                    cnt++;
                }
            }
        }
        if (cost < min_cost || (cost == min_cost && cnt < min_cnt)) {
            min_cost = cost;
            min_cnt = cnt;
            min_mask = mask;
        }
    }
    cout << min_cost << " " << min_cnt << endl;
    for (int i = 1; i <= m; i++) {
        if (min_mask & (1 << (i - 1))) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}