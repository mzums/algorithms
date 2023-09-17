#include <iostream>
using namespace std;

constexpr int MAXN = 1007;
int pref[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q, a, x1, x2, y1, y2;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a;
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + a;;
        }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << pref[x2][y2] - pref[x2][y1-1] - pref[x1-1][y2] + pref[x1-1][y1-1] << "\n";
    }
}