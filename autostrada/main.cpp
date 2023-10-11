#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

const int MAXN = 1e5+7;
pair <int, int> arr[MAXN];
int n, t;

bool check(double x) {
    double t2=0;
    for (int i = 0; i < n; ++i) {
        double v = arr[i].second + x;
        t2 += arr[i].first / v;
    }
    if (t2 <= t) return true;
    return false;
}

double bs(double l, double r) {
    double mid = (l + r) / 2;
    while (r-l > 0.0000001) {
        if (check(mid)) r = mid;
        else l = mid;
        mid = (l + r) / 2;
    }
    return mid;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t;
    for (int i = 0; i < n; ++i)
        cin >> arr[i].first >> arr[i].second;
    cout << fixed << setprecision(6) << bs(0, 1e9);
}