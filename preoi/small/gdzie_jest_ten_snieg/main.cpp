#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int MAXN = 2e5+7;
int arr[MAXN], l[MAXN], r[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k, b;
    cin >> t;
    while (t--) {
        int res = 1;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) cin >> arr[i];
        for (int i = 0; i < n; ++i) cin >> b;
        sort(arr, arr+n);

        int j = n - 1;
        for (int i = n-1; i >= 0; --i) {
            while (arr[j] - arr[i] > k) --j;
            r[i] = j - i + 1;
            if (i + 1 < n) r[i] = max(r[i], r[i+1]);
        }
        j = 0;
        for (int i = 0; i < n; ++i) {
            while (arr[i] - arr[j] > k) ++j;
            l[i] = i - j + 1;
            if (i > 0) l[i] = max(l[i], l[i-1]);
        }
        for (int i = 0; i < n-1; ++i)
            res = max(res, r[i+1] + l[i]);
        cout << res << "\n";
    }
}
