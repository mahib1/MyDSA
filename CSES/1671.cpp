#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>
#include <unordered_map>
 
using namespace std;
using ll = long long;
using pii = pair<ll, int>;
 
int main() {
  int n, m;
  cin >> n >> m;
 
  vector<vector<int>> edges(m, vector<int>(3, -1));
  for (int i = 0; i < m; i++) {
    cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
  }
 
  // now I have an edgelist
  // make adjlist
  unordered_map<int, vector<pii>> adj;
  for (auto edge : edges) {
    adj[edge[0]].push_back({edge[2], edge[1]});
  }
 
  // now I have adj list
  // now I apply dijkstra from node 1;
  priority_queue<pii, vector<pii>, greater<>> pq;
  vector<ll> dist(n + 1, LLONG_MAX);
  dist[1] = 0;
  pq.emplace(0, 1);
 
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d > dist[u]) continue;
 
    for (auto [w, v] : adj[u]) {
      if (dist[u] + w >= dist[v]) continue;
      dist[v] = dist[u] + w;
      pq.emplace(dist[v], v);
    }
  }
 
  for (int i = 1; i <= n; i++) {
    cout << dist[i] << " ";
  } cout << endl;
 
  return 0;
}
