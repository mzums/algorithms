// https://cses.fi/problemset/task/1750

#include <iostream>
using namespace std;

constexpr int MAXN = 2e5+7;
constexpr int LOG = 30;
int jump[MAXN][LOG];
int arr[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q, v, x;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    for (int i = 1; i <= n; ++i) jump[i][0] = arr[i];

    for (int j = 1; j < LOG; ++j)
        for (int i = 1; i <= n; ++i)
            jump[i][j] = jump[jump[i][j-1]][j-1];

    while (q--) {
        cin >> v >> x;
        int dist = 1 << LOG;
        for (int i = LOG; i >= 0; --i) {
            if (x >= dist) {
                v = jump[v][i];
                x -= dist;
            }
            dist >>= 1;
        }
        cout << v << '\n';
    }
}