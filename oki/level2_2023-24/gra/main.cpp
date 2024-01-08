#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAXN = 1e6+7;
int arr[MAXN][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, maxx;
    cin >> n >> arr[1][0];
    arr[1][1] = arr[1][0];
    arr[1][2] = arr[1][0];
    for (int i = 2; i <= n; ++i) {
        cin >> arr[i][0];
        arr[i][1] = max(arr[i-1][1], arr[i-1][2]) + arr[i][0];
        maxx = -2e9-7;
        for (int j = i-1; j >= max(1, i-5); --j) maxx = max(maxx, arr[j][1]);
        arr[i][2] = maxx;
    }
    cout << arr[n][1];
}