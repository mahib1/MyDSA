#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> edl(m);
    unordered_map<int, vector<pair<int, int>>> adl;   // forward adjacency list
    unordered_map<int, vector<int>> radl;             // reverse adjacency list

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        w = -w; // invert weight
        edl[i] = {u, v, w};
        adl[u].emplace_back(v, w);
        radl[v].emplace_back(u); // reverse edge for reachability to n
    }

    vector<long long> dist(n + 1, INF);
    dist[1] = 0;

    // Bellman-Ford for n - 1 times
    for (int i = 0; i < n - 1; ++i) {
        for (auto& [u, v, w] : edl) {
            if (dist[u] < INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Cycle detection (n-th iteration)
    vector<int> inCycle(n + 1, 0);
    for (auto& [u, v, w] : edl) {
        if (dist[u] < INF && dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            inCycle[v] = 1;
        }
    }

    // BFS function for reachability
    auto bfs = [&](int start, unordered_map<int, vector<pair<int, int>>>& graph) {
        vector<int> vis(n + 1, 0);
        queue<int> q;
        vis[start] = 1;
        q.push(start);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto& [nei, _] : graph[cur]) {
                if (!vis[nei]) {
                    vis[nei] = 1;
                    q.push(nei);
                }
            }
        }
        return vis;
    };

    // Convert radl to the correct type for bfs
    unordered_map<int, vector<pair<int, int>>> radl_wrapped;
    for (auto& [v, us] : radl) {
        for (int u : us)
            radl_wrapped[v].emplace_back(u, 0);
    }

    vector<int> reachFrom1 = bfs(1, adl);
    vector<int> reachFromN = bfs(n, radl_wrapped);

    for (int i = 1; i <= n; ++i) {
        if (inCycle[i] && reachFrom1[i] && reachFromN[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << -dist[n] << endl;
    return 0;
}

