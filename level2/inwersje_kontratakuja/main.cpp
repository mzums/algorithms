#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int,int>> input;
constexpr auto base = 1<<16;
int tree[2*base];
int n, i, in;
long long out;

void update(int odpl, int odpr, int aktl, int aktr, int v) {
    if (odpl > aktr || odpr < aktl) return;
    else if (aktl <= odpl && aktr >= odpr) ++tree[v];
    else {
        update(odpl, odpl+(odpr-odpl)/2, aktl, aktr, v*2);
        update(odpl+1+(odpr-odpl)/2, odpr, aktl, aktr, v*2+1);
    }
}
int read(int v) {
    int out=0;
    v += base;
    while (v >= 1) {
        out += tree[v];
        v = v / 2;
    }
    return out;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin>>in;
        input.push_back({in,i});
    }
    sort(input.begin(), input.end());
    for (auto para : input) {
        out += read(para.second);
        update(0, base-1, 0, para.second, 1);
    }
    cout << out;
}