#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

constexpr int maxn=1e6+7;
vector<int> pos[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i, t;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> t;
        pos[t].push_back(i);
    }
    int q, j, m, k, ind;
    cin >> q;
    vector<int>::iterator l, r, found;
    bool score;
    for (i = 0; i < q; ++i) {
        cin >> m;
        ind = 0;
        score = 0;
        for (j = 0; j < m; ++j) {
            cin >> t;
            l = pos[t].begin();
            r = pos[t].end();
            found = lower_bound(l, r, ind);
            if (found == r) score = 1;
            else ind = (*found)+1;
        }
        cout << (score ? "NIE" : "TAK") << '\n';
    }
}