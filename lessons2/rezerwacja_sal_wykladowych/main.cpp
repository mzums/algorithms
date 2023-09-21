#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXP = 3e4+7;
int dp[MAXP];
vector <int> endss[MAXP];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        endss[b].push_back(a);
    }
    for (int i = 1; i <= MAXP; i++) {
        if (endss[i].empty()) {
            dp[i] = dp[i-1];
            continue;
        }
        int maxx = 0;
        for (int j = 0; j < endss[i].size(); j++) {
            int len = i - endss[i][j];
            maxx = max(maxx, dp[i-len]+len);
        }
        dp[i] = max(dp[i-1], maxx);
    }
    cout << dp[30000];
}