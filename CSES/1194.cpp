
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
 
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
 
    vector<vector<char>> grid(n, vector<char>(m));
    pair<int, int> A;
    vector<pair<int, int>> monsters;
 
    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < m; ++j) {
            grid[i][j] = row[j];
            if (grid[i][j] == 'A') A = {i, j};
            if (grid[i][j] == 'M') monsters.push_back({i, j});
        }
    }
 
    vector<vector<int>> monsterDist(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> mq;
 
    for (auto [r, c] : monsters) {
        mq.push({r, c});
        monsterDist[r][c] = 0;
    }
 
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<char> dirChar = {'U', 'D', 'L', 'R'};
 
    // Monster BFS
    while (!mq.empty()) {
        auto [r, c] = mq.front(); mq.pop();
        for (auto [dr, dc] : dirs) {
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                grid[nr][nc] != '#' &&
                monsterDist[nr][nc] > monsterDist[r][c] + 1) {
                monsterDist[nr][nc] = monsterDist[r][c] + 1;
                mq.push({nr, nc});
            }
        }
    }
 
    // Player BFS
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<pair<int, char>>> parent(n, vector<pair<int, char>>(m, {-1, '.'}));
    vector<vector<int>> time(n, vector<int>(m, 0));
 
    q.push(A);
    vis[A.first][A.second] = true;
 
    pair<int, int> exitCell = {-1, -1};
    bool found = false;
 
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
 
        if (r == 0 || r == n - 1 || c == 0 || c == m - 1) {
            exitCell = {r, c};
            found = true;
            break;
        }
 
        for (int d = 0; d < 4; ++d) {
            int nr = r + dirs[d].first;
            int nc = c + dirs[d].second;
 
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (grid[nr][nc] == '#' || vis[nr][nc]) continue;
            if (time[r][c] + 1 >= monsterDist[nr][nc]) continue;
 
            vis[nr][nc] = true;
            time[nr][nc] = time[r][c] + 1;
            parent[nr][nc] = {r * m + c, dirChar[d]};
            q.push({nr, nc});
        }
    }
 
    if (!found) {
        cout << "NO\n";
        return 0;
    }
 
    // Backtrack path
    string path;
    int r = exitCell.first, c = exitCell.second;
    while (make_pair(r, c) != A) {
        auto [prevIdx, dir] = parent[r][c];
        path += dir;
        int pr = prevIdx / m, pc = prevIdx % m;
        r = pr, c = pc;
    }
 
    reverse(path.begin(), path.end());
    cout << "YES\n" << path.size() << "\n" << path << "\n";
    return 0;
}
