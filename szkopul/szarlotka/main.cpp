#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	set<ll> s;

	int n;
	ll k, a, pref = 0, minn = 1e18+7;
	cin >> n >> k;
	s.emplace(0);
	
	for (int i = 0; i < n; ++i) {
		cin >> a;
		pref += a;
		auto it = lower_bound(s.begin(), s.end(), pref-k);
		ll x = pref - *it;
		ll y = pref - *prev(it);
		minn = min(minn, min(abs(k-x), abs(k-y)));
		s.emplace(pref);
	}
	cout << minn;
}
