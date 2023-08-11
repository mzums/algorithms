#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n, a, summ=0;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> a;
        summ += a;
    }
    cout << (n*(n+1)) / 2 - summ;
}