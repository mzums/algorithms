#include <iostream>
using namespace std;
typedef long long ll;

ll factorial(int x, int p) {
    ll fac = 1;
    for (int i = x; i > 1; i--)
		fac = fac * i % p + p;
    return fac % p;
}

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    ll den = (factorial(n, p) * factorial(m, p)) % p;
    if (den == 0) den = p;
    cout << factorial(n+m, p) / den;
}