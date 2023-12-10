#include <iostream>
using namespace std;
typedef long long ll;

constexpr int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll factorial = 1;
    cout << "[1";
    for (int i = 2; i <= 1e9; ++i) {
        factorial = (factorial * i) % MOD;
        if (i % (int)1e6 == 0)
            cout << ", " << factorial;
    }
    cout << ']';
}