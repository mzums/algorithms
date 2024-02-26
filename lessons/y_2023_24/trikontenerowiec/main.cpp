#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

constexpr int MAXN = 1e6+7;
pair<int, int> arr[MAXN];
priority_queue<int> pq;

bool Sort(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n, w, h;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &w, &h);
        arr[i] = {w, h};
    }
    sort(arr, arr+n, Sort);
    int j = 0, res = 0;
    for (int i = 1; i <= m; ++i) {
        if (arr[j].second > i) {
            if (!pq.empty()) {
                res += pq.top();
                pq.pop();
            }
            continue;
        }
        while (arr[j].second <= i && j < n) {
            pq.push(arr[j].first);
            ++j;
        }
        if (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
    }
    printf("%d", res);
}