#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int SQRT = 1e4+7, MAXN = 3e4+7;
vector<int> primes;
bool is_prime[SQRT];
int last_divisible_by[SQRT];
int dp[MAXN], last[MAXN];
int arr[MAXN];
vector<int> res;

void sieve(int n) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
        for (int j = 2*i; j <= n; j+=i)
            is_prime[j] = false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill(is_prime, is_prime+SQRT, true);
    sieve(10000);
    for (int i = 0; i <= 1e4; i++)
        if (is_prime[i])
            primes.push_back(i);

    int n, maxx2 = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        int maxx = 0, indx = 0;
        for (int j = 0; j < primes.size(); j++)
            if (arr[i] % primes[j] == 0 && dp[last_divisible_by[primes[j]]] > maxx) {
                maxx = dp[last_divisible_by[primes[j]]];
                indx = last_divisible_by[primes[j]];

                int x = arr[i] / primes[j];
                if (x == 1 || x == primes[j] || dp[last_divisible_by[x]] <= maxx) continue;

                maxx = dp[last_divisible_by[x]];
                indx = last_divisible_by[x];
            }
        if (indx == 0) {
            dp[i] = 1;
            last[i] = 0;
        }
        else {
            dp[i] = maxx + 1;
            last[i] = indx;
        }

        for (int j = 0; j < primes.size(); j++)
            if (arr[i] % primes[j] == 0) {
                last_divisible_by[primes[j]] = i;
                last_divisible_by[arr[i] / primes[j]] = i;
            }
    }
    int x = 0;
    for (int i = 1; i <= n; ++i) {
        if (dp[i] > maxx2) {
            maxx2 = dp[i];
            x = i;
        }
    }
    while (x > 0) {
        res.push_back(x);
        x = last[x];
    }
    cout << res.size() << "\n";
    reverse(res.begin(), res.end());
    for (auto x : res) cout << x << " ";
    cout << "\n";
}