#include <iostream>
#include <vector>
#include <unordered_set>



using namespace std; 
#define ll long long

bool solved = false;

void dp(vector<int>& v, int currIdx, int n, unordered_set<int>& used) {
  if(currIdx == n) {
    for(int i = 0; i < n; i++) {
      cout << v[i] << " ";
    }

    cout << endl; 
    solved = true; 
    return;
  }

  for(int i = 1; i <= n; i++) {
    if(solved) return;

    if(used.find(i) != used.end()) continue; 

    if(currIdx > 0) {
      if(abs(i - v[currIdx - 1]) == 1) continue; 
    }
    
    v[currIdx] = i; 
    used.insert(i);
    dp(v, currIdx + 1, n, used);
    used.erase(i);
  }  
}


int main() {
  int n; cin >> n; 
  vector<int> v (n);
  unordered_set<int> used;

  dp(v, 0, n, used);

  if(!solved) {
    cout << "NO SOLUTION" << endl; 
    return 0;
  }

  return 0; 
}
