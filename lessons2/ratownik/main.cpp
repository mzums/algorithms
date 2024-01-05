#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, x, y, a, b, res=0;
    cin >> n >> k >> x >> y;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        double dist = sqrt(abs(a-x)*abs(a-x) + abs(b-y)*abs(b-y));
        if (dist > k) ++res;
    }
    cout << res;
}