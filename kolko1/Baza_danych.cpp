#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, p;
    long long k;
    map<long long, int> m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k >> p;
        if (m.find(k) == m.end()) {
            if (p >= 0) {
                m[k] = p;
                cout << p << "\n";
            }
            else
                cout << "NIE\n";
        }
        else if (m[k] + p < 0)
            cout << "NIE\n";
        else if (m[k] + p >= 0) {
            m[k] += p;
            cout << m[k] << "\n";
        }
    }
}   