#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a;
    ll res = 0;
    priority_queue<ll> q;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        q.push(-a);
    }
    while (!q.empty()) {
        ll x = -q.top();
        q.pop();
        if (q.empty()) continue;
        ll y = -q.top();
        q.pop();
        q.push(-x-y);
        res += x + y;
    }
    cout << res;
}