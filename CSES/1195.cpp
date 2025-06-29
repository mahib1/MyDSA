#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<vector<ll>> dist(n + 1, vector<ll>(2, LLONG_MAX));
    priority_queue<tuple<ll, int, bool>, vector<tuple<ll, int, bool>>, greater<>> pq;

    dist[1][0] = 0;
    pq.push({0, 1, 0}); // (cost, node, discount_used)

    while (!pq.empty()) {
        auto [cost, u, used] = pq.top();
        pq.pop();

        if (cost > dist[u][used]) continue;

        for (auto &[v, w] : adj[u]) {
            // Without discount
            if (cost + w < dist[v][used]) {
                dist[v][used] = cost + w;
                pq.push({dist[v][used], v, used});
            }

            // With discount (only once)
            if (!used) {
                ll discounted = cost + (w / 2);
                if (discounted < dist[v][1]) {
                    dist[v][1] = discounted;
                    pq.push({discounted, v, 1});
                }
            }
        }
    }

    cout << min(dist[n][0], dist[n][1]) << endl;
    return 0;
}
