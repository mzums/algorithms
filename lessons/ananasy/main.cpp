#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e6+7;
int arr[MAXN], arr2[MAXN], w[MAXN];
int n, a, b, score=-1e9-7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> arr2[0] >> arr2[1];
    arr[0] = 0;
    arr[1] = arr2[1] - arr2[0];
    for (int i = 2; i < n; i++) {
        cin >> arr2[i];
        arr[i] = arr2[i] - arr2[i-1];
    }
    for (int i = n-1; i >= 1; i--) {
        w[i] = max(w[i+1] + arr[i], arr[i]);
        score = max(score, w[i]);
    }
    cout << score;
}