#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int cycleFound = 0;
vector<int> cyclePath;
unordered_map<int , int> parent;

int dfs(int u, unordered_map<int , vector<int>>& adj, vector<int>& state) {
  state[u] = 1;

  for(int v : adj[u]) {
    if(state[v] == 0) {
      parent[v] = u;
      if(dfs(v, adj, state)) return 1;
    } else if (state[v] == 1) {
      cycleFound = 1;
      cyclePath.push_back(v);

      int curr = u;
      while(curr != v) {
        cyclePath.push_back(curr);
        curr = parent[curr];
      }

      cyclePath.push_back(v);
      reverse(cyclePath.begin(), cyclePath.end());
      return 1;
    }
  }

  state[u] = 2;
  return 0;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  unordered_map<int , vector<int>> adl;
  for(int i = 0; i < m; i++) {
    int u , v;
    cin >> u >> v;

    adl[u].push_back(v);
  }

  vector<int> state (n + 1, 0);

  for(int i = 1; i <= n; i++) {
    if(state[i] == 0) {
      if(dfs(i, adl, state)) break;
    }
  }

  if(cycleFound) {
    cout << cyclePath.size() << endl;
    
    for(int x : cyclePath) {
      cout << x << " ";
    } cout << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}
