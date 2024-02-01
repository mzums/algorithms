#include <iostream>
#include <list>
using namespace std;

constexpr int MAXN = 5007;
int a[MAXN], b[MAXN], c[MAXN];
bool visited[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string res = "";
    cin >> n;
    list<int> l;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[j] == b[i] && !visited[j]) {
                c[j] = i;
                visited[j] = 1;
                break;
            }

    for (int i = 0; i < n; ++i)
        l.push_back(c[i]);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n-i; ++j) {
            int a = *l.begin();
            int b = *next(l.begin());
            if (a < b) {
                l.pop_front();
                l.push_back(a);
                res += '0';
            }
            else {
                l.pop_front();
                l.pop_front();
                l.push_front(a);
                l.push_back(b);
                res += '1';
            }
        }
        for (int j = 0; j < i; ++j) {
            int a = *l.begin();
            l.pop_front();
            l.push_back(a);
            res += '0';
        }
    }
    cout << res;
}