#include <iostream>
using namespace std;
typedef long long ll;

const int MAXN = 1e3+7;
int pool2[2*MAXN][2*MAXN];
ll pref[2*MAXN][2*MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, r, x, y, z, a;

    cin >> n >> r;
    int n2 = 2*n+5;
    for (int y = 1; y <= n; ++y)
        for (x = 1; x <= n; ++x) {
            cin >> a;
            pool2[x-y+n+1][x+y+1] = a;
        }

    for (int y = 1; y <= n2; ++y)
        for (int x=1; x<=n2; ++x)
            pref[x][y] = pref[x-1][y] + pref[x][y-1] - pref[x-1][y-1] + (ll)pool2[x][y];

    for (int i = 1; i <= r; ++i) {
        cin >> y >> x >> z;
        int x_45 = x - y + n + 1;
        int y_45 = x + y + 1;
        int x2 = min(x_45 + z, n2-1);
        int y2 = min(y_45 + z, n2-1);
        int x1 = max(x_45 - z, 1);
        int y1 = max(y_45 - z, 1);
        ll res = pref[x2][y2] - pref[x1-1][y2]- pref[x2][y1-1]+ pref[x1-1][y1-1];
        cout << res << "\n";
    }
}