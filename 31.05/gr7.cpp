#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000;

vector<int> graph[MAXN];
int degree[MAXN];

void dfs(int v, bool used[]) {
    used[v] = true;
    for (int u : graph[v]) {
        if (!used[u]) {
            dfs(u, used);
        }
    }
}

bool check_euler_path() {
    int odd_vertices = 0; 
    for (int i = 0; i < MAXN; i++) {
        if (graph[i].size() > 0) {
            degree[i] = graph[i].size();
            if (degree[i] % 2 == 1) {
                odd_vertices++;
            }
        }
    }
    if (odd_vertices > 2) {
        return false;
    }
    bool used[MAXN] = { false };
    int start_vertex = -1;
    for (int i = 0; i < MAXN; i++) {
        if (degree[i] > 0) {
            start_vertex = i;
            break;
        }
    }
    dfs(start_vertex, used);
    for (int i = 0; i < MAXN; i++) {
        if (degree[i] > 0 && !used[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if (!check_euler_path()) {
        cout << "Cannot lay out all dominoes in one line" << endl;
        return 0;
    }

    cout << "All dominoes can be laid out in one line" << endl;

    return 0;
}