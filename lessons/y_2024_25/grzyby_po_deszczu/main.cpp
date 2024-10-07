#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

constexpr int MAXN = 1e6+7;
ll arr[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, t;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    ll summ = arr[0], res = arr[0];
    for (int i = 1; i < n; ++i) {
        summ += arr[i];
        ll x = ceil((double)(t-i)/2) * arr[i-1];
        res = max(res, summ + x + (t-i)/2 * arr[i]);
    }
    cout << res << "\n";
}