#include <iostream>
using namespace std;
typedef long long ll;

ll debt[17], subset_sum[1 << 17], score[1 << 17];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a;
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> a;
            debt[i] += a;
        }
    for (int i = 1; i < (1 << n); ++i) {
        int x = __lg(i);
        subset_sum[i] = subset_sum[i ^ (1 << x)] + debt[x];
    }
    for (int i = 1; i < (1 << n); ++i) score[i] = n;

    for (int mask = 1; mask < (1 << n); ++mask)
        for (int submask = mask; submask > 0; submask = (submask - 1) & mask)
            if (subset_sum[submask] == 0) {
                int siz = __builtin_popcount(submask);
                score[mask] = min(score[mask], score[mask ^ submask] + siz - 1);
            }
    
    cout << score[(1 << n) - 1] << "\n";
}
