#include <iostream>
#include <vector>
using namespace std;

int n, k, m, cnt = 0;
vector<int> colors; // цвета лампочек (от 1 до k)
vector<vector<int>> wires; // провода (список смежности)

void backtrack(int cur) {
    if (cur == n) { // все лампочки раскрашены
        cnt++;
        return;
    }
    for (int i = 1; i <= k; i++) { // перебираем все цвета
        colors[cur] = i;
        bool valid = true;
        for (int j : wires[cur]) { // проверяем провода
            if (colors[j] == i) {
                valid = false;
                break;
            }
        }
        if (valid) backtrack(cur+1);
    }
}

int main() {
    cin >> n >> k >> m;
    colors.resize(n);
    wires.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // переводим в нумерацию с 0
        wires[u].push_back(v);
        wires[v].push_back(u);
    }
    backtrack(0);
    cout << cnt << endl;
    return 0;
} 