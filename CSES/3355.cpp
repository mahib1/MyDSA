#include <iostream>
#include <cmath>

void solve() {
    long long n;
    std::cin >> n;

    for (long long a = 0; a * a <= n; ++a) {
        for (long long b = a; a * a + b * b <= n; ++b) {
            for (long long c = b; a * a + b * b + c * c <= n; ++c) {
                long long rem = n - (a * a + b * b + c * c);
                long long d = sqrt(rem);
                if (d * d == rem) {
                    std::cout << a << " " << b << " " << c << " " << d << "\n";
                    return;
                }
            }
        }
    }
}

int main() {
    int t;
    if (!(std::cin >> t)) return 0;
    while (t--) solve();
    return 0;
}
