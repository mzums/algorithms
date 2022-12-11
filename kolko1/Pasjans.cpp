#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 5e5 + 7;
int arr[MAXN];
int n;
string out;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<int, int> m;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    out += "1\n";
    m.insert({arr[0], 1});
    for (int i = 1; i < n; i++) {
        auto it = m.lower_bound(arr[i] + 1);
        if (*it > arr[i]) {
            cout << arr[i] << " " << *it << "\n";
            place = m[it];
            m.erase(it);
            m.insert({arr[i], 0});
        }
        else
            cout << 1 << "\n";
    }
}