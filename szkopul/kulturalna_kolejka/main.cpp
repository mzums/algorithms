#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAXN = 2e5+7;
int dp[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string str;
    cin >> n >> str;
    str = str + ' ';
    int i = 0;
    reverse(str.begin(), str.end());

    if (str[1] == 'X') dp[1] = 1;
    int last = dp[1], res = dp[1];
    for (int i = 2; i <= n; ++i) {
        if (str[i] == 'X') {
            dp[i] = max(last + 2, i);
            last = dp[i];
        }
        res = max(res, dp[i]);
    }
    cout << res << "\n";
}