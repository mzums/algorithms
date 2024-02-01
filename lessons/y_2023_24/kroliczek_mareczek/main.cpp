#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 1e6+7;
ll arr[MAXN][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i][0];
        arr[i][1] = arr[i-1][2] + arr[i][0];
        arr[i][2] = max(arr[i-1][1], arr[i-1][2]);
    }
    cout << max(arr[n][1], arr[n][2]);
}