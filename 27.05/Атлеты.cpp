#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct segment_tree {
    vector<int>tree;
    int m = 1;
    segment_tree(int n) {
        while (m < n)m *= 2;
        tree.resize(2 * m - 1);
    }
    void update(int i, int val, int v, int lx, int rx) {
        if (rx - lx == 1) {
            tree[v] += val;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid)update(i, val, v * 2 + 1, lx, mid);
        else update(i, val, v * 2 + 2, mid, rx);
        tree[v] = (tree[v * 2 + 1] + tree[v * 2 + 2]);
    }
    void update(int i, int val) {
        update(i, val, 0, 0, m);
    }
    int op(int l, int r, int v, int lx, int rx) {
        if (l >= rx || lx >= r)return 0;            
        if (lx >= l && rx <= r)return tree[v];
        int mid = (lx + rx) / 2;
        return (op(l, r, v * 2 + 1, lx, mid) + op(l, r, v * 2 + 2, mid, rx));  
    }
    int op(int l, int r) {
        return op(l, r, 0, 0, m);
    }
};

int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    segment_tree t(m + 2);
    vector<vector<int>>v(p, vector<int>(2));
    for (int i = 0; i < p; ++i)cin >> v[i][0] >> v[i][1];
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int sum = 0;
    queue<int>q;
    for (int i = 0; i < p; ++i) {
        if (i > 0 && v[i][0] != v[i - 1][0]) {
            while (!q.empty()) {
                int top = q.front();
                q.pop();
                t.update(top, 1);
            }
        }
        q.push(v[i][1]);
        sum += t.op(0, v[i][1]);
    }
    cout << sum;
    return 0;
}