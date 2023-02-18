#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2e4+7;
int n, k, cost, score, l, r, score2;
int arr[MAXN];

int solve() {
    cost = r = score2 = 0;
    for (int l = 0; l < n; l++) {
        while (r < l && cost > k) {
            cost -= max(0, arr[r + 1] - arr[r]);
            r++;
        }
        if (cost <= k) score2 = max(l - r + 1, score2);
        cost += max(0, arr[l + 1] - arr[l]);
    }
    return score2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    score = solve();
    reverse(arr, arr+n);

    cout << max(score, solve());
}