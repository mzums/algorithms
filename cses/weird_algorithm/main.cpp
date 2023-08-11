#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n;
    cin >> n;
    while (n != 1) {
        cout << n << " ";
        if (n%2 == 0) n /= 2;
        else n = n*3 + 1;;
    }
    cout << n;
}