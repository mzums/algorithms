#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

constexpr int MAXN = 1007;
int bfab[MAXN], kfab[MAXN], zfab[MAXN];

int bs(int n, int x) {
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (zfab[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int b, k, z, n1, n2, n3, maxx=0, maxb, maxk, maxz, maxsum;
    cin >> b >> k >> z;
    cin >> n1;
    for (int i = 0; i < n1; ++i) {
        cin >> bfab[i];
        maxx = max(maxx, bfab[i]);
    }
    maxb = b * maxx;
    maxx = 0;
    cin >> n2;
    for (int i = 0; i < n1; ++i) {
        cin >> kfab[i];
        maxx = max(maxx, kfab[i]);
    }
    maxk = k * maxx;
    maxx = 0;
    cin >> n3;
    for (int i = 0; i < n1; ++i) {
        cin >> zfab[i];
        maxx = max(maxx, zfab[i]);
    }
    maxz = z * maxx;
    sort(bfab, bfab+n3);

    maxsum = maxb + maxk + maxz;
    cout << maxsum << "\n";
    int ans=0, res=0;
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            int summ = b * bfab[i] + k * bfab[j];
            res = bs(n3, ceil((maxsum-summ)/z));
            cout << res << "\n";
            ans += n3 - res;
        }
    }
    cout << ans;
}