#include <iostream>
using namespace std;

const int MAXN = 1e5+7;
int arr[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k, a, l, d, sum_l, act;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> l >> d;
        sum_l = 0, act = a;
        while (sum_l < l) {
            ++arr[act];
            act += d;
            ++sum_l;
        }
    }
    for (int i = 1; i <= n; i++) cout << arr[i] << " ";
}