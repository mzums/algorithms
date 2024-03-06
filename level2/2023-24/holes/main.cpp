#include <iostream>
#include <cmath>
using namespace std;

constexpr int MAXN = 3e5+7;
int arr[MAXN], next_sqrt[MAXN], how_many[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, op, a, b;
    cin >> n >> m;
    int sqroot = ceil(sqrt(n));
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    for (int i = n; i > 0; --i) {
        if (i + arr[i] > n) {
            next_sqrt[i] = i;
            if (i + arr[i] > n) how_many[i] = 1;
        }
        else if (i/sqroot != (i + arr[i]) / sqroot) {
            next_sqrt[i] = i + arr[i];
            how_many[i] = 1;
        }
        else {
            next_sqrt[i] = next_sqrt[i + arr[i]];
            how_many[i] = how_many[i + arr[i]] + 1;
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> op;
        int res = 1;
        if (op == 1) {
            cin >> a;
            int a2 = a, hm = 0;
            while (a <= n) {
                a2 = a;
                hm += how_many[a];
                a = next_sqrt[a];
                if (arr[a] + a > n) break;
            }
            if (a2/sqroot != a/sqroot) hm += how_many[a];
            cout << a << " " << hm << "\n";
        }
        else {
            cin >> a >> b;
            arr[a] = b;
            int start_sqrt = a / sqroot * sqroot;
            for (int i = a; i >= start_sqrt; --i) {
                if (i + arr[i] > n) {
                    next_sqrt[i] = i;
                    if (i + arr[i] > n) how_many[i] = 1;
                }
                else if (i/sqroot != (i + arr[i]) / sqroot) {
                    next_sqrt[i] = i + arr[i];
                    how_many[i] = 1;
                }
                else {
                    next_sqrt[i] = next_sqrt[i + arr[i]];
                    how_many[i] = how_many[i + arr[i]] + 1;
                }
            }
        }
    }
}