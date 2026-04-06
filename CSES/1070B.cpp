#include <iostream>
#include <vector>


using namespace std;

int main() {
  int n; cin >> n; 
  if(!n || n == 2 || n == 3) {
    cout << "NO SOLUTION" << endl; 
    return 0;
  }

  vector<int> v(n);
  for(int i = 2; i <= n; i += 2) {
    v[i/2 - 1] = i;
  }

  for(int i = 1; i <= n; i += 2) {
    v[(i/2) + n/2] = i;
  }

  for(int i = 0; i < n; i++) {
    cout << v[i] << " "; 
  }

  cout << endl; 
  return 0; 
}
