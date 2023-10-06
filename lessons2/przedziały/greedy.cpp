#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAXN = 1e6+7;
pair<int, int> arr[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, topp=0, res=0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i].second >> arr[i].first;
    sort(arr, arr+n);

    for (auto el : arr)
        if (el.second >= topp){
            topp = el.first;
            ++res;
        }
    cout << res;
}
