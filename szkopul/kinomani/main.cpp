#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

constexpr int MAXN = 25e4+7;
vector<pair<pair<int, int>, int>> v;
vector<int> G[MAXN];
priority_queue<int> pq;
int x[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, cnt = 0, res = 0;
    cin >> n;
    for (int i = 1; i <= 2*n; ++i) pq.push(-i);
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b;
        v.push_back({{a, 1}, i});
        v.push_back({{b, -1}, i});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i <= 2*n; ++i) {
        if (v[i].first.second == 1) {
            ++cnt;
            G[-pq.top()].push_back(v[i].second);
            x[v[i].second] = -pq.top();
            pq.pop();
        } else {
            --cnt;
            pq.push(-x[v[i].second]);
        }
        res = max(res, cnt);
    }
    cout << res << "\n";
    for (int i = 1; i <= res; ++i) {
        cout << G[i].size() << " ";
        for (int j : G[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }
}