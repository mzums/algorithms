#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, p;
    long k;
    map<long, int> m;
    map<long, int>::iterator it;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k >> p;
        it = m.find(k);
        if (it == m.end() && m[k] + p >= 0) {
            m[k] = p;
            cout << p << "\n";
        }
        else if (m[k] + p < 0)
            cout << "NIE\n";
        else if (it != m.end() && m[k] + p >= 0) {
            m[k] += p;
            cout << m[k] << "\n";
        }
    }
}