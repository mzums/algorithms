#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e6+7;
pair <int, int> arr[MAXN];
int n, score=1, last;

bool Sort(pair <int, int> &a, pair <int, int> &b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr+n, Sort);
    last = arr[0].second;

    for (int i = 1; i < n; i++)
        if (arr[i].first > last) {
            last = arr[i].second;
            score++;
        }
    cout << score;
}