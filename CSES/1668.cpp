#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
 
using namespace std; 
 
 
vector<int> parent, r;

//union find implementation
 
int find(int x) {
  if(parent[x] == x) return x; 
  return parent[x] = find(parent[x]);
}
 
void un(int x, int y) {
  x = find(x); 
  y = find(y);
 
  if(r[x] > r[y]) parent[y] = x; 
  else parent[x] = y;
 
  if(r[x] == r[y]) r[y]++;
}
 
 
int main () {
  int n, m; 
  cin >> n >> m; 
 
  vector<vector<int>> edl (m); 
  parent.resize(n + 1);
  r.resize(n + 1);
 
  for(int i = 1; i <= n; i++) {
    parent[i] = i; 
    r[i] = 0;
  }
 
  for(int i = 0; i < m; i++) {
    int a, b; 
    cin >> a >> b;
    edl[i] = {a, b};
 
    un(a, b);
  }
 
  queue<int> q;
  vector<int> color (n + 1, -1);
 
  unordered_map<int, vector<int>> adl; 
  for(auto e: edl) {
    adl[e[0]].push_back(e[1]);
    adl[e[1]].push_back(e[0]);
  }
 
  vector<int> discon;
 
  for(int i = 1; i <= n; i++) {
    if(parent[i] == i) discon.push_back(i);
  }
 
  for(int i : discon) {
    q.push(i);
    color[i] = 0;
    while(!q.empty()) {
      int c = q.front(); q.pop(); 
 
      for(int nei : adl[c]) {
        if(color[nei] == -1) {
          color[nei] = color[c] ^ 1; 
          q.push(nei);
        } else if(color[nei] == color[c]) {
          cout << "IMPOSSIBLE\n"; 
          return 0;
        }
      }
    }
 
  }
 
  for(int i = 1; i <= n; i++) {
    cout << color[i] + 1 << " ";
  } cout << endl;
  return 0;
}
