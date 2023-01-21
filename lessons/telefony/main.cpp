#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e6+7;
pair<int, int> arr[MAXN];
int n, x;

void solve(int x, int i) {
    arr[i].first += x % 10 * 100;
    arr[i].first += (x % 100 - x % 10);
    arr[i].first += (x % 1000 - x % 100) / 100;
    arr[i].first += (x - x % 1000);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].second;
        solve(arr[i].second, i);
    }
    sort(arr, arr+n);
    for (int i = 0; i < n; i++)
        cout << arr[i].second << " ";
}