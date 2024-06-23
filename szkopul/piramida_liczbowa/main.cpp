#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long arr[5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;
    cout << n << "\n";
    arr[0] = n;
    for (long long i = sqrt(n)+1; i >= 1; --i) {
        if (n % i == 0) {
            arr[0] = i;
            arr[1] = n/i;
            cout << i << " " << n/i << "\n";
            break;
        }
    }
    if (k == 2) return 0;
    long long two = __gcd(arr[0], arr[1]);
    cout << arr[0]/two << " " << two << " " << arr[1]/two << "\n";
}