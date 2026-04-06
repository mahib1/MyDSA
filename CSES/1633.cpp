#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std; 

const int MOD = 1e9 + 7;

#define ll long long

ll solve(int n, vector<int>& dp) {
  if(n < 0) return 0;
  if(n == 0) return 1; 

  if(dp[n] != -1) return dp[n];

  int ways = 0; 
  for(int i = 1; i <= 6; i++) {
    ways = (ways + (solve(n - i, dp) % MOD)) % MOD;
  }

  return dp[n] = ways;
} // top down 


ll solve(int curr, int n, vector<int>& dp) {
  if(curr == n) return 1; 
  if(curr > n) return 0; 

  if(dp[curr] != -1) return dp[curr];

  int ways = 0; 
  for(int i = 1; i <= 6; i++) {
    ways = (ways + (solve(curr + i, n, dp)  % MOD)) % MOD; 
  }

  return dp[curr] = ways;
}

ll solve(int n) {
  //tabulation
  vector<ll> dp(n + 1, 0);
  dp[0] = 1; 

  for(int i = 1; i <= n; i++) {
    for(int d = 1; d <= 6; d++) {
      if(i - d < 0) continue;  // out of bounds

      dp[i] = (dp[i] + (dp[i-d] % MOD)) % MOD;
    }
  }

  return dp[n];
}


int main() {
  int n; cin >> n; 
  vector<int> dp (n + 1, -1);

  cout << solve(n) << endl;
}
