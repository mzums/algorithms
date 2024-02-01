#include <iostream>
using namespace std;

const int MAXN = 5e5+7;
int arr[MAXN];

bool check(int x, int n) {
    int how_many = 0;
    for (int i = 0; i < n;) {
        int curr = 0;
        if (x < arr[i]) return 0;
        while (i < n && curr+arr[i] <= x) {
            curr += arr[i];
            i++;
        }
        how_many++;
    }
    return how_many <= x;
}

int bs(int l, int r, int n) {
    int mid;
    while (l+1 < r) {
        mid = (l+r) / 2;
        if (check(mid, n)) r = mid;
        else l = mid;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << bs(0, 1e9, n);
}