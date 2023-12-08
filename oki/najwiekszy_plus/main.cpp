#include <iostream>
using namespace std;

constexpr int MAXN = 4e5+7;
int arr[MAXN], pref[MAXN];

bool check(int n, int x) {
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i-1];
        if (arr[i] <= x) ++pref[i];
    }
    for (int i = x+1; i <= n - x; ++i)
        if (arr[i] >= 2*x+1 && (pref[i-x-1] - pref[i+x] == 0))
            return true;
    return false;
}

int bs(int n) {
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (!check(n, mid)) r = mid;
        else l = mid + 1;
    }
    return l - 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    cout << bs(n);
}