#include <iostream>
#include <set>
using namespace std;

const int MAXN = 1e8+107;
bool arr[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n, a, sum=0;
    set <int> s;
    s.insert(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        sum += a;
        auto it = s.find(sum);
        if (it != s.end()) {
            cout << "TAK";
            return 0;
        }
        s.insert(sum);
    }
    cout << "NIE";
}