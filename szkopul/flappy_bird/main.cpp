#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, finish, a=0, b=0, x=0;
    cin >> n >> finish;
    for (int i = 0; i < n; i++) {
        int x2, a2, b2;
        cin >> x2 >> a2 >> b2;
        int d = x2 - x;
        int a3 = max(a-d, a2+1);
        int b3 = min(b+d, b2-1);
        if ((a3+int(1e9))%2 != x2%2) a3 += 1;
        if ((b3+int(1e9))%2 != x2%2) b3 -= 1;
        if (b3 < a3) {
            cout << "NIE";
            return 0;
        }
        x = x2;
        a = a3;
        b = b3;
    }
    cout << (x+a) / 2;
}