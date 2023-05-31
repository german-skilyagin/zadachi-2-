#include <iostream>
#include <vector>
using namespace std;

const int N = 105;
const int W = 1005;
int w[N], l[N];
int dp[N][W];

int main() {
    int n, max_weight;
    cin >> n >> max_weight;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> l[i];
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= max_weight; j++) {
            dp[i][j] = dp[i - 1][j]; 
            if (j >= w[i]) { 
                int new_val = dp[i - 1][j - w[i]] + l[i]; 
                if (new_val > dp[i][j]) { dp[i][j] = new_val; }
            }
        }
    }
    cout << dp[n][max_weight] << endl;
    vector<int> selected_items;
    int i = n, j = max_weight;
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            selected_items.push_back(i);
            j -= w[i];
        }
        else { i--; }
    }
    cout << "Selected items: ";
    for (int i = selected_items.size() - 1; i >= 0; i--) {
        cout << selected_items[i] << " ";
    }
    cout << endl;
    return 0;
}