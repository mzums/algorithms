#include <iostream>
#include <iomanip>
using namespace std;
typedef long long ll;

constexpr int MAXN = 1e6+7, INF = 1e9;
ll x[MAXN], y[MAXN];

ll polygonArea(int n) {
    ll area = 0;
    int j = n - 1;
    for (int i = 0; i < n; i++) {
        area += (x[i+1] - x[i]) * (y[i+1] + y[i]);
    }
    return abs(area);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%lld%lld", &x[i], &y[i]);
        x[i] += INF;
        y[i] += INF;
    }
    x[n] = x[0];
    y[n] = y[0];

    ll result = polygonArea(n);

    if (result % 2 == 0)
        printf("%lld", (result / 2));
    else
        printf("%lld.5", ((result - 1) / 2));
}
