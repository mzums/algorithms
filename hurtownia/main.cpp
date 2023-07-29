#include <iostream>
#include <algorithm>
using namespace std;

struct day {
    int a, b, n;
};

const int MAXN = 1 << 18;
day arr[MAXN];
int pref[MAXN];
int n, cost, score, bb;

bool Sort(day x, day y) {
    if (x.b != y.b) return x.b < y.b;
    return x.a > y.a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].a;
        arr[i].n = i;
        pref[i] = pref[i-1] + arr[i].a;
    }
    for (int i = 1; i <= n; i++) cin >> arr[i].b;
    sort(arr+1, arr+n+1, Sort);

    for (int i = 1; i <= n; i++)
        if (arr[i].b <= pref[arr[i].n]) {
            score++;
            for (int j = 0; j <= n; j++) pref[j] -= arr[i].b;
        }

    cout << score;
}