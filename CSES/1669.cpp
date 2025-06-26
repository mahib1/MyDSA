#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
 
using namespace std;
 
bool cycleFound = false;
vector<int> cyclePath;
 
bool dfs(int u, int p, unordered_set<int>& visited,
         unordered_map<int, int>& parent,
         unordered_map<int, vector<int>>& adj) {
 
    visited.insert(u);
    parent[u] = p;
 
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
 
        if (visited.count(v)) {
            cycleFound = true;
            vector<int> currentCycle;
            int curr = u;
            while (curr != v) {
                currentCycle.push_back(curr);
                curr = parent[curr];
            }
            currentCycle.push_back(v);
            reverse(currentCycle.begin(), currentCycle.end());
 
            cyclePath = currentCycle;
            cyclePath.push_back(v);
            return true;
        }
 
        if (dfs(v, u, visited, parent, adj)) {
            return true;
        }
    }
    return false;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    cin >> n >> m;
 
    unordered_map<int, vector<int>> adj;
 
    for (int i = 0; i < m; i++) {
        int u_node, v_node;
        cin >> u_node >> v_node;
        adj[u_node].push_back(v_node);
        adj[v_node].push_back(u_node);
    }
 
    unordered_set<int> visited;
    unordered_map<int, int> parent;
 
    for (int i = 1; i <= n; i++) {
        if (!visited.count(i)) {
            if (dfs(i, -1, visited, parent, adj)) {
                break;
            }
        }
    }
 
    if (cycleFound) {
        cout << cyclePath.size() << endl;
        for (int i = 0; i < cyclePath.size(); ++i) {
            cout << cyclePath[i] << (i == cyclePath.size() - 1 ? "" : " ");
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
 
    return 0;
}
