#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

constexpr int MAXN = 1e6+7;
int arr[MAXN];
map<ll, int> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, res=0;
    ll pref=0;
    string str;
    cin >> n >> k;
    cin >> str;
    str = ' ' + str;
    m[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (str[i] == 'R') arr[i] = -k;
        else if (str[i] == 'O') arr[i] = 1;
        pref += arr[i];
        if (m.find(pref) == m.end()) {
            m[pref] = i;
        }
        else {
            int x = m[pref];
            res = max(res, i - x);
        }
    }
    cout << res;
}