
#include <bits/stdc++.h>
using namespace std;

int dfs(int node, int end, unordered_map<int, vector<int>>& adl, vector<int>& dp, vector<int>& par, vector<int>& vis) {
  if (node == end) return 1;
  if (vis[node]) return INT_MIN; // cycle
  if (dp[node] != -1) return dp[node];

  vis[node] = 1;
  int longest = INT_MIN;

  for (int nbr : adl[node]) {
    int npath = dfs(nbr, end, adl, dp, par, vis);
    if (npath != INT_MIN && 1 + npath > longest) {
      longest = 1 + npath;
      par[node] = nbr;
    }
  }

  vis[node] = 0;
  return dp[node] = longest;
}

int main() {
  int n, m;
  cin >> n >> m;

  unordered_map<int, vector<int>> adl;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adl[u].push_back(v);
  }

  vector<int> dp(n + 1, -1);      // dp[i] = longest path from i to n
  vector<int> par(n + 1, -1);     // par[i] = next node on path from i
  vector<int> vis(n + 1, 0);      // cycle protection

  int res = dfs(1, n, adl, dp, par, vis);

  if (res == INT_MIN) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  cout << res << "\n";

  int curr = 1;
  while (curr != -1) {
    cout << curr << " ";
    if (curr == n) break;
    curr = par[curr];
  }
  cout << "\n";

  return 0;
}

