#include <iostream>
using namespace std;
typedef long long ll;
    
ll nwd(__int128 a, __int128 b) {
	__int128 pom;
  	while(b!=0) {
    	pom = b;
    	b = a%b;
    	a = pom;  
  	}
    return a;
}

__int128 nww(ll a, ll b) {
    return (__int128)a*b/nwd(a, b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, a, b, c, d;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c >> d;
        ll e = (__int128)a*(nww(b,d))/b + (__int128)c*(nww(b,d)/d);
        __int128 f = nww(b,d);
        cout << (ll)e/nwd(e,f) << " " << (ll)f/nwd(e,f) << "\n";
    }
}