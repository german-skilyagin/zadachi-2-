#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000;
vector<int> graph[MAXN]; 
bool used[MAXN][MAXN]; 

void dfs(int v, vector<int>& path) {
    while (!graph[v].empty()) {
        int u = graph[v].back();
        graph[v].pop_back(); 
        if (!used[v][u]) {
            used[v][u] = used[u][v] = true; 
            dfs(u, path); 
        }
    }
    path.push_back(v); 
}

int main() {
    int n, m;
    cin >> n >> m;
    int odd_vertex = -1; 
    vector<int> degree(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    for (int i = 0; i < n; i++) {
        if (degree[i] % 2 == 1) { 
            if (odd_vertex == -1) {
                odd_vertex = i;
            }
            else {
                graph[odd_vertex].push_back(i); 
                graph[i].push_back(odd_vertex);
                degree[odd_vertex]++;
                degree[i]++;
                odd_vertex = -1;
            }
        }
    }
    vector<int> path;
    dfs(0, path);
    cout << "Eulerian cycle: ";
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] + 1 << " "; 
    }
    cout << endl;
    return 0;
}