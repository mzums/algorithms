#include <iostream>
#include <vector>
using namespace std;

constexpr int MAXN = 1007;
bool composite[MAXN];

void erathosthenes() {
    for (int i = 2; i <= 1000; ++i)
        for (int j = i*i; j <= 1000; j+=i)
            composite[j] = 1;
}

vector<int> factorize(int a) {
    vector<int> factors;
    for (int i = 2; i*i <= a; ++i)
        while (a % i == 0) {
            factors.push_back(i);
            a /= i;
        }
    if (a > 1) factors.push_back(a);
    return factors;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a;
    cin >> n;
    erathosthenes();
    for (int i = 0; i < n; ++i) {
        cin >> a;
        vector<int> factors = factorize(a);
        for (auto factor : factors) cout << factor << " ";
        cout << "\n";
    }
}