#include <iostream>
typedef long long ll;
using namespace std;

const int MOD = 10000007;

ll szyPot(ll a, int n) {
    ll score = 1;
	while(n > 0) {
		if (n%2 == 1)
			score = (score*a) % MOD;
		a = (a*a) % MOD;
		n /= 2;
	}
	return score;
}

int main() {
    int n, b;
    ll a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << szyPot(a, b) << "\n";    
    }
}