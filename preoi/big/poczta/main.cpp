#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
typedef long long ll;

constexpr int MAXN = 1e6+7, INF = 1e9+7;
int k[MAXN];
vector<vector<ll>> dp, cost;
vector<queue<pair<ll, ll>>> Q;
priority_queue<pair<ll, pair<int, ll>>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a;
    ll h;
    cin >> n >> h;
    Q.resize(n+1);
    dp.push_back({});
    cost.push_back({});
    for (int i = 1; i <= n; ++i) {
        dp.push_back({});
        cost.push_back({});
        cin >> k[i];
        dp[i].push_back(0);
        cost[i].push_back(INF);
        for (int j = 1; j <= k[i]; ++j) {
            cin >> a;
            if (dp[i][j-1] > 0) {
                dp[i].push_back(a);
                cost[i].push_back(min(dp[i][j], cost[i][j-1]));
            }
            else {
                dp[i].push_back(dp[i][j-1] + a);
                cost[i].push_back(min(dp[i][j], cost[i][j-1]));
            }

            if (dp[i][j] > 0) {
                Q[i].push({cost[i][j], dp[i][j]});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!Q[i].empty()) {
            auto [x, y] = Q[i].front();
            Q[i].pop();
            pq.push({x, {i, y}});
        }
    }
    while(!pq.empty()) {
        ll c = pq.top().first;
        if (c+h < 0) {
            cout << h << "\n";
            return 0;
        };
        int no = pq.top().second.first;
        ll d = pq.top().second.second;
        h += d;
        pq.pop();
        if (!Q[no].empty()) {
            long long x2, y;
            tie(x2, y) = Q[no].front();
            Q[no].pop();
            pq.push({x2, {no, y}});
        }
    }
    cout << h << "\n";
}