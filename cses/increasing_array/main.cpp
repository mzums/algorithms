#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, a, b;
    long long result=0;
    cin >> n >> a;
    b = a;
    for (int i = 1; i < n; i++) {
        cin >> a;
        if (a < b) {
            result += b-a;
            a += b-a;
        }
        b = a;
    }
    cout << result;
}