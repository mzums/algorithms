#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAXN = 1e5+7;
int arr1[MAXN], arr2[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    string str1, str2;
    cin >> n >> m;
    cin >> str1 >> str2;
    str1 = " " + str1;
    str2 = " " + str2;

    int j = 1;
    arr1[0] = -1e9;
    for (int i = 1; i <= m; ++i) {
        arr1[i] = 1e9;
        for (j; j <= n; ++j)
            if (str2[i] == str1[j]) {
                arr1[i] = j;
                ++j;
                break;
            }
    }
    arr1[m+1] = 1e9;
    j = n;
    arr2[0] = -1e9;
    for (int i = m; i > 0; --i) {
        arr2[i] = -1e9;
        for (j; j > 0; --j)
            if (str2[i] == str1[j]) {
                arr2[i] = j;
                --j;
                break;
            }
    }
    arr2[m+1] = 1e9;
    int minn = 1e9;
    for (int i = 0; i <= m; ++i) {
        if (arr1[i] == 1e9) break;
        int idx = upper_bound(arr2, arr2+m+1, arr1[i]) - arr2;
        minn = min(minn, max(idx-i-1, 0));
    }
    cout << minn << "\n";
}