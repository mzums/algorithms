#include <iostream>
using namespace std;

const int MOD = 1e6+9;
constexpr int MAXN = 1e6+7;
int divs_count[MAXN];

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void preprocess_divisors() {
    for (int i = 1; i < MAXN; ++i) {
        for (int j = i; j < MAXN; j += i) {
            divs_count[j]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    preprocess_divisors();

    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;
        int d = gcd(a, b);
        cout << divs_count[d] << "\n";
    }
}
