#include <iostream>
#include <vector>


using namespace std; 


int main() {
  int n, k; cin >> n >> k; 
  vector<int> v (n);
  for(int i = 0; i < n; i++) cin >> v[i]; 
  int left = 0; 
  int sum = 0; 
  int ans = 0; 

  for(int i = 0; i < n; i++) {
    sum += v[i];
    while(sum > k && left <= i) {
      sum -= v[left]; left++; 
    }

    if(sum == k) ans ++; 
  }

  cout << ans << endl; 
  return 0; 
}
