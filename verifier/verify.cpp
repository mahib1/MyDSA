#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
#define ll long long

int main() {
  ifstream f1("output.txt");
  ifstream f2("expected.txt");

  if (!f1) {
    cerr << "Error opening output.txt.\n";
    return 1;
  }

  if (!f2) {
    cerr << "Error opening expected.txt.\n";
    return 1;
  }

  ll num1, num2;
  ll index = 0;

  while (true) {
    // Read from file1
    while (f1 >> num1) {
      // Read from file2
      if (!(f2 >> num2)) {
        cout << "Mismatch at index " << index << ": file1 = " << num1 << ", file2 = <EOF>\n";
        return 0;
      }

      if (num1 != num2) {
        cout << "Mismatch at index " << index << ": file1 = " << num1 << ", file2 = " << num2 << "\n";
        return 0;
      }

      index++;
    }

    // Check if file2 has extra numbers
    if (f2 >> num2) {
      cout << "Mismatch at index " << index << ": file1 = <EOF>, file2 = " << num2 << "\n";
    } else {
      cout << "Files matched successfully.\n";
    }

    break;
  }

  return 0;
}
