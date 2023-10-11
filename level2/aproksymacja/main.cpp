#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

const int MAXN = 1e6+7;
int arr[MAXN];

bool check(double x, int n) {
    double prev=arr[0]-x, curr, maxx;
    for (int i = 1; i < n; ++i) {
        curr = arr[i] - x;
        maxx = arr[i] + x;
        if (prev > maxx) return false;
        else prev = max(prev, curr);
    }
    return true;
}

double bs(int n) {
    double l=0, r=1e6+7;
    while (r-l > 0.0001) {
        double mid = (l + r) / 2;
        if (check(mid, n)) r = mid;
        else l = mid;
    }
    return l;
}

void answer(double x, int n) {
    double prev=arr[0]-x, curr;
    cout << prev << "\n";
    for (int i = 1; i < n; ++i) {
        curr = arr[i] - x;
        prev = max(prev, curr);
        cout << prev << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    double res = bs(n);;
    cout << fixed << setprecision(4) << res << "\n";
    answer(res, n);
}