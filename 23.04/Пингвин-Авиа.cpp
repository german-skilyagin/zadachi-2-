#include <vector>
#include <iostream>
#include <string>
#include <map>


#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
using namespace std;

vi par;
vi rnk;
int getP(int v) {
    if (v == par[v]) { return v; }
    return par[v] = getP(par[v]);
}

void merg(int a, int b) {
    a = getP(a);
    b = getP(b);
    if (a != b) {
        if (rnk[a] < rnk[b]) { swap(a, b); }
        par[b] = a;
        if (rnk[a] == rnk[b]) { rnk[a]++; }
    }
}

void init(int n) {
    par.resize(n + 1);
    rnk.resize(n + 1);
    for (int i = 1; i <= n; i++) { par[i] = i; rnk[i] = 0; }
}


void solve(){
    int n, d, a;
    cin >> n >> d >> a;
    vector<string> g(n);
    init(n);
    rep(i, 0, n) { cin >> g[i]; }
    map<pair<int, int>, bool> added;
    vector<string> g_ans(n);
    rep(i, 0, n) { g_ans[i] = string(n, '0'); }
    ll ans = 0;
    rep(i, 0, n) {
        rep(j, 0, sz(g[i])) {
            if (g[i][j] == '1' and added.find({i, j}) == added.end() and added.find({j, i}) == added.end()) {
                added[ {i, j}] = true;
                if (getP(i + 1) != getP(j + 1)) { merg(i + 1, j + 1); }
                else { ans += d; g_ans[i][j] = 'd';  g_ans[j][i] = 'd'; }
            }
        }
    }
    vi vis(n + 1, -1);
    vi rem;
    rep(i, 1, n + 1) { vis[getP(i)] = 1; }
    rep(i, 1, n + 1) { if (vis[i] != -1) { rem.pb(i); } }
    for (int i = 1; i < sz(rem); i++) {
        g_ans[rem[0] - 1][rem[i] - 1] = 'a';
        g_ans[rem[i] - 1][rem[0] - 1] = 'a';
        ans += a;
    }
    cout << ans << endl;
    rep(i, 0, n) { rep(j, 0, n) { cout << g_ans[i][j]; } cout << endl; }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) { solve(); }
    return 0;
}