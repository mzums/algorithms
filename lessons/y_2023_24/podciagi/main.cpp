#include <iostream>
#include <map>
using namespace std;

const int MAXN = 5*1e5+7;
const int MOD = 1e9+7;
long long dp[MAXN];
map<int, int> last;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a;
    cin >> n;
    dp[0] = 1;
    last.clear();

    for (int i = 1; i <= n; i++) {
        cin >> a;
        dp[i] = (2 * dp[i - 1] - (last.find(a) != last.end() ? dp[last[a] - 1] : 0) + MOD) % MOD;
        last[a] = i;
    }
    cout << dp[n];
}
