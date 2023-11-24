#include <iostream>
#include <vector>
using namespace std;

constexpr int MAXN = 507;
int arr1[MAXN], arr2[MAXN], dp[MAXN], parent[MAXN];
    
int main() {
    int n, m, ans = 0, indx;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr1[i];
    cin >> m;
    for (int j = 0; j < m; ++j) cin >> arr2[j];

    for (int i = 0; i < n; ++i) {
        int curr = 0, last_one = -1;
        for (int j = 0; j < m; ++j)
            if (arr1[i] == arr2[j] && curr + 1 > dp[j]) {
                dp[j] = curr + 1;
                parent[j] = last_one;
            }
            else if (arr1[i] > arr2[j] && dp[j] > curr) {
                curr = dp[j];
                last_one = j;
            }
    }
    for (int i = 0; i < m; ++i)
        if (dp[i] > ans) {
            ans = dp[i];
            indx = i;
        }
    vector<int> res;
    if (ans > 0)
        while (indx != -1) {
            res.push_back(arr2[indx]);
            indx = parent[indx];
        }
    cout << ans << "\n";
    for (int i = ans - 1; i >= 0; --i)
        cout << res[i] << " ";
}
