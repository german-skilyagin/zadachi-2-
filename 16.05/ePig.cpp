#include <iostream>
using namespace std;
bool mm[100][200];
int mk[200], rk[100], mn[100], rn[100], qn[100], mc[100][100], res[100];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) mm[0][i] = true, mk[i] = 1;
    memset(mc, 0, sizeof(mc)); 
    memset(mn, 0, sizeof(mn));
    mn[0] = k;
    memset(res, -1, sizeof(res));
    int ck = (n - 1) * k, it = 0;
    while (ck) {
        memset(rk, -1, sizeof(rk)); 
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < k; ++j) 
                if (!mm[i][j] && (rk[i]<0 || mk[rk[i]] > mk[j])) rk[i] = j;
        memset(rn, -1, sizeof(rn));
        for (int i = 0; i < n; ++i) {
            if (rk[i] < 0) continue;
            int t = rk[i];
            for (int j = 0; j < n; ++j)
                if (mm[j][t] && (rn[i]<0 || mn[rn[i]] > mn[j])) rn[i] = j;
        }
        memset(qn, -1, sizeof(qn));
        for (int i = 0; i < n; ++i) {
            if (rn[i] < 0) continue;
            int t = rn[i]; 
            if (qn[t] < 0 || mc[t][qn[t]] < mc[t][i] || (mc[t][qn[t]] == mc[t][i] && mn[qn[t]] > mn[i])) qn[t] = i;
        }
        for (int i = 0; i < n; ++i) { 
            if (qn[i] < 0) continue;
            --ck;
            ++mc[qn[i]][i];
            ++mn[qn[i]];
            ++mk[rk[qn[i]]];
            mm[qn[i]][rk[qn[i]]] = true;
            if (mn[qn[i]] == k) res[qn[i]] = it + 1;
        }
        ++it;
    }
    for (int i = 1; i < n; ++i) cout << res[i] << " ";
    return 0;
}