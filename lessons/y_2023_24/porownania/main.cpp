#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

constexpr int MAXN = 2e5+7, P = 137, MOD = 1e6+7;
ll H[MAXN], powP[MAXN];
string str;

int get_hash(int a, int b) {
	return (H[b] - H[a-1] + MOD) % MOD;
}

int check(int a, int b, int l) {
	int h1 = get_hash(a, a+l-1);
	int h2 = get_hash(b, b+l-1);
	if (a < b)
		h1 = (h1 * powP[b-a]) % MOD;
	else
		h2 = (h2 * powP[a-b]) % MOD;

	if (h1 == h2) return 0;
	if (str[a+l-1] < str[b+l-1]) return -1;
	else return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q, a, b, c;
	cin >> str >> q;
	str = ' ' + str;int n = str.size();
	powP[0] = 1;
	for (int i = 1; i <= n; ++i)
		powP[i] = (powP[i-1] * P) % MOD;
	for (int i = 1; i <= n; ++i)
		H[i] = (H[i-1] + powP[i] * str[i]) % MOD;

	for (int i = 0; i < q; ++i) {
		cin >> a >> b >> c;
		int l = 0, r = c, mid;
		while (l < r) {
			mid = (l+r) / 2;
			if (check(a, b, mid) == 0) {
				l = mid + 1;
			}
			else r = mid;
		}
		if (check(a, b, r) == 0) cout << "=\n";
		else if (check(a, b, r) == -1) cout << "<\n";
		else cout << ">\n";
	}
}
