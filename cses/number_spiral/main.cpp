#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, x, y, value;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> y >> x;
        if (x > y)
            if (x % 2) value = x*x - y + 1;
            else value = (x-1) * (x-1) + y;
        else
            if (y % 2) value = (y-1) * (y-1) + x;
            else value = y*y - x + 1;
        cout << value << "\n";
    }
}