#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, a, score=18;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        score += a;
    }
    cout << score/(n+1);
}