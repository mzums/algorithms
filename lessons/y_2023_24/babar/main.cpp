#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAXN = 5007;
int dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str1, str2, ans;
    cin >> str1 >> str2;
    int n = str1.size(), m = str2.size();
    str1 = ' ' + str1;
    str2 = ' ' + str2;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (str1[i] == str2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (str1[i] == str2[j]) {
            ans += str1[i];
            --i, --j;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            --i;
        else
            --j;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    cout << ans << "\n";
}