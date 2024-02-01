#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

void solve(ll a, ll b) {
    ll nwd = __gcd(a, b);
    ll a2 = a, b2 = b;
    a2 /= nwd, b2 /= nwd;
    nwd = __gcd(a, b2);
    b2 /= nwd;
    cout << a2 << " " << b2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        solve(a, b);
    }
}