#include <iostream>
using namespace std;
typedef long long ll;

const int MOD = 123456789;

struct M {
    ll a11, a12, a21, a22;
};

M matrix_mul(M a, M b) {
    M res;
    res.a11 = (a.a11 * b.a11 + a.a12 * b.a21) % MOD;
    res.a12 = (a.a11 * b.a12 + a.a12 * b.a22) % MOD;
    res.a21 = (a.a21 * b.a11 + a.a22 * b.a21) % MOD;
    res.a22 = (a.a21 * b.a12 + a.a22 * b.a22) % MOD;
    return res;
}

M matrix_pow(M A, int n) {
    if (n == 1) return A;
    M x = matrix_pow(A, n/2);
    if (n % 2 == 0) return matrix_mul(x, x);
    return matrix_mul(matrix_mul(x, x), A);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    if (n == 1) cout << 1;
    else cout << matrix_pow({1, 1, 1, 0}, n-1).a11;
}