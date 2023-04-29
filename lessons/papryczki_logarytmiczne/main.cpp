#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, a;
    long long score=0;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> a;
        score += a * pow(2, i);
    }
    cout << score + 1;
}