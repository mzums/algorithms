#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Tree {
    ll a, b, c;
};

const int MAXN = 1e6+7;
Tree arr[MAXN];

bool sort_c(Tree x, Tree y) {
    return x.c > y.c;
}
bool sort_a(Tree x, Tree y) {
    return x.a > y.a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k, res=0;
    cin >> n >> k;
    k = min(k, n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].a >> arr[i].b;
        arr[i].c = k * arr[i].a + arr[i].b;
    }
    sort(arr, arr+n, sort_c);
    sort(arr, arr+k, sort_a);
    for (int i = 0; i < k; i++)
        res = max(res, i * arr[i].a);
    for (int i = k; i < n; i++)
        res = max(res, k * arr[i].a + arr[i].b);
    cout << res;
}