#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, ll>> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    vector<ll> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);
    int x = -1;

    for (int i = 1; i <= n; i++) {
        x = -1;
        for (auto [u, v, w] : edges) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                x = v;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        // reconstruct cycle
        for (int i = 0; i < n; i++) x = parent[x];

        vector<int> cycle;
        int curr = x;
        do {
            cycle.push_back(curr);
            curr = parent[curr];
        } while (curr != x || cycle.size() == 1);

        cycle.push_back(x);
        reverse(cycle.begin(), cycle.end());

        if(cycle.size() == 3 && cycle[0] == cycle[1]) {
            cout << cycle[0] << " " << cycle[1] << endl;
            return 0;
        }

        for (int v : cycle) cout << v << " ";
        cout << "\n";
    }

    return 0;
}
