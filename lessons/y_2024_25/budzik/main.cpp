#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAX_A = 1e6+7;
vector<int> smallest_prime_factor(MAX_A);

void precompute_sieve() {
    for (int i = 2; i <= MAX_A; i++) smallest_prime_factor[i] = i;
    for (int i = 2; i * i <= MAX_A; i++) {
        if (smallest_prime_factor[i] == i) {
            for (int j = i * i; j <= MAX_A; j += i)
                if (smallest_prime_factor[j] == j)
                    smallest_prime_factor[j] = i;
        }
    }
}

ll solve(int a) {
    int pierw = sqrt(a);
    if (pierw * pierw == a) return -1;

    ll res = 1;
    while (a > 1) {
        int p = smallest_prime_factor[a];
        int exp = 0;
        while (a % p == 0) {
            exp++;
            a /= p;
        }
        if (exp % 2 == 1) exp++;
        while (exp--) res *= p;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    precompute_sieve();

    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        ll res = solve(a);
        if (res == -1)
            cout << "KWADRAT\n";
        else
            cout << res << '\n';
    }
}
