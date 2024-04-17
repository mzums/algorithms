#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

constexpr int MAXN = 1e6+7;
multiset<pair<ll, ll>> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k, a, cnt = 0;
    string ans;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        s.insert({a, i});
    }

    while (!s.empty()) {
        ll minn = s.begin()->first;
        ll x1 = s.begin()->second;
        ll maxx = s.rbegin()->first;
        ll x2 = s.rbegin()->second;
        ll summ = minn + maxx;

        if (minn == k) {
            ++cnt;
            ans += "1 " + to_string(x1) + " " + to_string(minn) + "\n";
            s.erase({minn, x1});
            continue;
        }
        if (maxx == k) {
            ++cnt;
            ans += "1 " + to_string(x2) + " " + to_string(maxx) + "\n";
            s.erase({maxx, x2});
            continue;
        }
        if (x1 == x2) {
            ++cnt;
            if (minn <= k)
                ans += "1 " + to_string(x1) + " " + to_string(minn) + "\n";
            else {
                ans += "1 " + to_string(x1) + " " + to_string(k) + "\n";
                s.insert({minn-k, x1});
            }
            s.erase({minn, x1});
            continue;
        }
        if (summ > k) {
            ++cnt;
            s.erase({minn, x1});
            s.erase({maxx, x2});
            if (summ != k) s.insert({summ-k, x2});
            ans += "2 " + to_string(x1) + " " + to_string(minn) + " " + to_string(x2) + " " + to_string(k-minn) + "\n";
        }
        else {
            ++cnt;
            s.erase({minn, x1});
            s.erase({maxx, x2});
            ans += "2 " + to_string(x1) + " " + to_string(minn) + " " + to_string(x2) + " " + to_string(maxx) + "\n";
        }
    }
    if (cnt > n) cout << "NIE\n";
    else {
        cout << "TAK\n";
        cout << ans;
    }
    if (cnt < n) {
        for (int i = 0; i < n-cnt; ++i)
            cout << "0\n";
    }
}