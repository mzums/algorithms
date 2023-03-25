#include <iostream>
#include <algorithm>
using namespace std;

struct edge{
    int a, b, t;
};

const int MAXN = 1e6+7;
edge arr[MAXN];
int connections[MAXN];
bool phoneboxes[MAXN];
int n, m, k;

bool Sort(const edge &a, const edge &b) {
    return (a.t < b.t);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> x;
        phoneboxes[x] = true;
    }

    for (int i = 0; i < m; i++) {
        cin >> arr[i].a >> arr[i].b >> arr[i].t;
        connections[arr[i].a]++;
        connections[arr[i].b]++;
    }

    sort(arr, arr+m, Sort);
    for (int i = 0; i < m; i++)
        if (--connections[arr[i].a] <= 1 || --connections[arr[i].b] <= 1) {
            cout << arr[i].t-1;
            return 0;
        }
}