#include <iostream>
using namespace std;
typedef long long ll;

constexpr int MAXN = 3e6+7;
ll arr[MAXN], arr2[MAXN], arr3[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b;
        arr[a] = b;
        arr2[a+1] += 1;
        arr2[a+b+1] -= 1;
    }
    for (int i = 1; i <= m; ++i) {
        arr2[i] += arr2[i-1];
        arr3[i] = arr3[i-1] + arr[i] - arr2[i];
    }
    ll maxx = 0, minn = 1e18, maxx1=1, minn1=1;
    for (int i = 1; i <= m; ++i) {
        if (arr3[i] > maxx) {
            maxx = arr3[i];
            maxx1 = i;
        }
        if (arr3[i] < minn) {
            minn = arr3[i];
            minn1 = i;
        }
    }
    cout << maxx1 << " " << minn1 << "\n";
}