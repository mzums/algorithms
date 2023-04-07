#include <iostream>
using namespace std;

const int MAXN = 1007, INF = 1e9+7;
int arr[MAXN][MAXN];
string arr2[MAXN][MAXN];
int n, m, q, u, v, w;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i == j) arr[i][j] = 0;
            else arr[i][j] = INF;
            arr2[i][j] = to_string(i);
        }

    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        arr[u][v] = w;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (arr[i][j] > arr[i][k] + arr[k][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                    arr2[i][j] = string(arr2[i][k] + " " + arr2[k][j]);
                }

    for (int i = 1; i <= q; i++) {
        cin >> u >> v;
        if (u == v)
            cout << arr[u][v] << " 1 " << v << "\n";
        else if (arr[u][v] == INF)
            cout << "NIE\n";
        else
            cout << arr[u][v] << " " << arr2[u][v].length() << " " << arr2[u][v] << " " << v << "\n";
    }
}