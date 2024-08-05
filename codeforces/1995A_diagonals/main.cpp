#include <iostream>
#include <cmath>
using namespace std;

int solve(double n, int k) {
    int curr = 0, res = 0;
    n = n - 0.5;
    while (curr < k) {
        curr += ceil(n);
        ++res;
        n = n - 0.5;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << solve(n, k) << '\n';
    }
}