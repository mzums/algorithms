#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int base = 1<<17;
int tree[base*2]{};
int x, y, n, a, b, c;

int read(int v) {
    v += base;
    int maks = 0;
    while (v > 0) {
        maks = max(tree[v],maks);
        v /= 2;
    }
    return maks;
}

void write(int odpl, int odpr, int zapl, int zapr, int v, int w) {
    if (odpr < zapl || odpl > zapr);
    else if (odpl >= zapl && odpr <= zapr) tree[v] = max(tree[v], w);
    else {
        write(odpl, odpl+(odpr-odpl)/2, zapl, zapr, v*2, w);
        write(odpl+1+(odpr-odpl)/2, odpr, zapl, zapr, v*2+1, w);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> x >> y >> n;
    vector<int> v(2);
    map <vector<int>,int> in;
    for (int i = 0; i < n; ++i)
        cin >> v[1] >> v[0] >> in[v];

    int prev = 0, xi, ind = 1;
    map <int,int> odp;
    vector <int> xv;

    for (auto i : in) xv.push_back(i.first[1]);
    sort(xv.begin(), xv.end());

    for (auto xii : xv) {
        odp[xii] = ind++;
        prev = xii;
    }

    int out = 0;
    for (auto it : in) {
        a = it.first[0];
        b = it.first[1];
        c = it.second;
        write(0, base-1, odp[b], base-1, 1, read(odp[b])+c);
        out = max(out,read(odp[b]));
    }
    cout << out;
}