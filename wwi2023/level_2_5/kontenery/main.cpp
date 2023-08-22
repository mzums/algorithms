#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 1e5+7;
int arr[MAXN], arr2[500][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n, k, a, l, d, sum_l, act;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> l >> d;
        sum_l = 0, act = a;
        if (d < sqrt(n)) {
            arr2[d][a]++;
            if (a+l*d <= n) arr2[d][a+l*d]--;
        }
        else {
            while (sum_l < l) {
                ++arr[act];
                act += d;
                ++sum_l;
            }
        }
    }
    for (int i = 1; i <= sqrt(n); i++)
        for (int j = i; j <= n; j++)
            arr2[i][j] += arr2[i][j-i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sqrt(n); j++)
            arr[i] += arr2[j][i];
        cout << arr[i] << " ";
    }
}