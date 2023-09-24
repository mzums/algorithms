#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 5*1e5+7, INF = 1e9;
int count[MAXN];
pair <int, int> arr[MAXN];
bool active[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k, p, res=0, cnt_active=0;
    cin >> n >> k >> p;
    for (int i = 0; i < p; i++) {
        cin >> arr[i].first;
        count[i] = INF;
    }
    for (int i = p-1; i >= 0; i--) {
        arr[i].second = count[arr[i].first];
        count[arr[i].first] = i;
    }
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < p; i++) {
        int car = arr[i].first;
        if (!active[car]) {
            cnt_active++;
            res++;
            active[car] = true;
        }
        if (cnt_active > k) {
            auto [_, car] = q.top();
            q.pop();
            active[car] = false;
            cnt_active--;
        }
        q.push({arr[i].second, car});
    }
    cout << res;
}