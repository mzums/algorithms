#include <iostream>
using namespace std;

const int MAXN = 1007;
int n, m, a, b, q;
int arr[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[a][b] = true;
        arr[b][a] = true;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        if (arr[a][b]) cout << "TAK\n";
        else cout << "NIE\n";
    }
}