#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    vector<vector<bool>>friends(1 + n, vector<bool>(1 + n));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int v;
            cin >> v;
            friends[i][j] = (v == 1);
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (friends[i][k] && friends[k][j]) {
                    friends[i][j] = true;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i != s && friends[s][i]) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}