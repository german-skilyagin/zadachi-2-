#include <vector>
#include <iostream>
#include <set>
#include <queue>
using namespace std;

const int maxx = 1000;

struct Node {
    vector<Node*> out;
    int de;
    bool vis;
} nodes[maxx + 1];

int main(){
    for (int i = 0; i < maxx + 1; i++) { nodes[i].de = maxx; }
    int N, K, M, first, last, id, lastid;
    cin >> N;
    while (N--) {
        cin >> K;
        vector<int> ids;
        while (K--) { cin >> id, ids.push_back(id); }
        for (int i = 0; i < ids.size() - 1; i++) {
            nodes[ids[i]].out.push_back(nodes + ids[i + 1]);
            nodes[ids[i + 1]].out.push_back(nodes + ids[i]);
        }
    }
    cin >> M >> first;
    last = first;
    while (--M) { cin >> last; }
    queue<Node*> Que;
    Que.push(nodes + first);
    nodes[first].de = 0;
    while (!Que.empty()) {
        auto node = Que.front();
        Que.pop();
        for (auto n : node->out)
            if (n->de > node->de + 1) { n->de = node->de + 1, Que.push(n); }
    }
    set<Node*> ans;
    Que.push(nodes + last);
    while (!Que.empty()) {
        auto node = Que.front();
        Que.pop();
        ans.insert(node);
        for (auto n : node->out)
            if (n->de == node->de + 1 && !n->vis) { Que.push(n), n->vis = true; }
    }
    for (auto a : ans) { cout << a - nodes << " "; }
}