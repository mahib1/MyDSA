#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
 
#define pb push_back
 
std::vector<std::vector<int>> dirns = {{1,0}, {-1,0}, {0,1}, {0,-1}};
 
void dfs(std::unordered_set<int>& vis, int i, std::vector<std::vector<int>>& grid, int n, int m) {
  if(vis.count(i)) return; 
  if(i >= n*m) return;
  
  int r = i / m;
  int c = i % m;
 
  vis.insert(i);
 
  for(int j = 0; j < 4; j++) {
    int nr = r + dirns[j][0];
    int nc = c + dirns[j][1]; 
 
    if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
    if (grid[nr][nc] != 1) continue;
 
    int ni = nr * m + nc;
    if(vis.count(ni)) continue;
 
    dfs(vis, ni, grid, n, m);
  }
}
 
void solver(std::vector<std::vector<int>>& grid) {
  using namespace std;
 
  unordered_set<int> vis;
  queue<int> q;
 
  int n = grid.size(); 
  int m = grid[0].size();
  int ans = 0;
 
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int idx = i * m + j;
      if(grid[i][j] != 1) continue;
 
      if(vis.count(idx)) continue;
 
      dfs(vis, idx, grid, n, m);
      ans++;
    }
  }
 
 
  std::cout << ans << std::endl;
}
 
 
void solve() {
  int n, m; 
  std::cin >> n >> m;
 
  using namespace std; 
  vector<vector<int>> grid (n, vector<int>(m, 0)); //0 for wall 1 for floor
  
  for(int r = 0; r < n; r++) {
    std::string in; 
    std::cin >> in;
 
    for(int c = 0; c < m; c++) {
      grid[r][c] = (in[c] == '.') ? 1 : 0;
    }
  }
 
  solver(grid);
}
 
 
int main () {
  solve();
  return 0;
}
