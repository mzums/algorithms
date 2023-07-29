#include <iostream>
using namespace std;

typedef long long ll;
ll a, b, m;

__int128_t solve(__int128_t a, __int128_t b, __int128_t m) {
    if (b == 0) return 1;
    __int128_t res = solve(a, b/2, m);
    res = (__int128_t)(res * res) % m;
    if (b%2 == 0) return res;
    return (res * a) % m;
}

int main() {
    cin >> a >> b >> m;
    cout << (ll)solve(a, b, m);
}