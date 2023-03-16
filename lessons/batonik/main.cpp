#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e6+7;
long long arr[MAXN], scores[MAXN];
long long n, result, minn=-1e6-7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        scores[i] = max(scores[i-1]+arr[i], (long long)0);
        result = max(result, scores[i]);
        minn = max(minn, arr[i]);
    }
    if (minn < 0) cout << minn;
    else cout << result;
}