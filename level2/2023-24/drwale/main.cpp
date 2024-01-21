#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;

constexpr int MAXN = 5e6+7;
int arr[MAXN], cnt[2*MAXN];
bitset<MAXN> dp;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, summ = 0, res = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        summ += arr[i];
    }
    sort(arr, arr+n);
    int maxx = arr[n-1];
    summ -= maxx;
    for (int i = 0; i < n-1; ++i) ++cnt[arr[i]];
    for (int i = 1; i <= summ; ++i) {
        if (cnt[i] > 2) {
            int tmp = 2 - (cnt[i] % 2);
            cnt[2*i] += (cnt[i] - tmp) / 2;
            cnt[i] = tmp;
        }
        for (int j = 0; j < cnt[i]; ++j) v.push_back(i);
    }
    dp[0] = 1;
    for (auto i : v)
        dp |= (dp << i);

    for (int i = 0; i <= summ/2; ++i)
        if (dp[i]) res = i;

    cout << res + maxx;
}