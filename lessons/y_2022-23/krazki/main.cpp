#include <iostream>
using namespace std;

const int MAXN = 1e6+7;
int arr[MAXN], arr2[MAXN];
int n, m, a, i, j;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    arr[0] = 1e9+7;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        arr[i] = min(arr[i-1], a);
    }
    for (int i = 1; i <= m; i++) cin >> arr2[i];

    i = n; j = 1;
    while (i > 0 && j <= n) {
        if (i <= 0 || j > n || arr2[j] == 0) break;
        do i--;
        while (arr[i] < arr2[j] && i > 0);
        j++;
    }
    cout << i;
}