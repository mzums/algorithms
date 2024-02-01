#include <iostream>
using namespace std;

const int MAXN = 1e3+7;
int pref[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, r, a, b, c, d;
    cin >> n >> r;
    for (int i = 1 ; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> pref[i][j];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            pref[i][j] += pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];

    for (int i = 1 ; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a = max(0, i-r);
            b = max(0, j-r);
            c = min(n, i+r);
            d = min(n, j+r);
            cout << pref[c][d] - pref[a - 1][d] - pref[c][b - 1] + pref[a - 1][b - 1] << " ";
        }
        cout << "\n";
    }
}