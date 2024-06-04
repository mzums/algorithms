#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct S {
    int val, prev;
};
constexpr int MAXN = 2007;
int arr1[MAXN], arr2[MAXN];
S arr[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, idx = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int i = 0; i < m; i++) cin >> arr2[i];

    for (int i = 0; i < n; ++i) {
        S x = {0, -1};
        for (int j = 0; j < m; ++j)
            if (arr1[i] == arr2[j] && arr[j].val < x.val + 1)
                arr[j] = {x.val + 1, x.prev};
            else if (arr1[i] > arr2[j] && arr[j].val > x.val)
                x = {arr[j].val, j};
    }
    S res = {0, 0};
    for (int i = 0; i < m; i++)
        if (arr[i].val > res.val)
            res = {arr[i].val, i};

    cout << res.val << "\n";
    vector<int> lcs;
    while (res.prev != -1) {
        lcs.push_back(arr2[res.prev]);
        res.prev = arr[res.prev].prev;
    }
    reverse(lcs.begin(), lcs.end());
    for (int num : lcs) cout << num << " ";
}