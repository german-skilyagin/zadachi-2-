#include <iostream>
#include <vector>
using namespace std;



int main()
{
    int inf = 100;
    int n, m, a, b, min_dist, vertex;
    cin >> n;
    vector<vector<pair<int32_t, int>>>g(n + 1);
    vector<bool>colour(n + 1, false);
    vector<int>dist(n + 1, inf);
    vector<int>cost(n + 1); 
    for (size_t i = 1; i <= n; ++i) cin >> cost[i];
    cin >> m;
    while (m--)
    {
        cin >> a >> b;
        g[a].emplace_back(b, cost[a]);
        g[b].emplace_back(a, cost[b]);
    }
    min_dist = 0;
    dist[1] = 0;
    vertex = 1;
    while (min_dist < inf)
    {
        colour[vertex] = true;
        for (auto& i : g[vertex])
        {
            if (dist[i.first] > dist[vertex] + i.second){ dist[i.first] = dist[vertex] + i.second; }
        }
        min_dist = inf;
        for (size_t edge = 1; edge <= n; ++edge)
        {
            if (!colour[edge] and min_dist > dist[edge]){ vertex = edge;min_dist = dist[edge]; }
        }
    }
    dist[n] != inf ? cout << dist[n] << endl : cout << -1 << std::endl;
    return 0;
}