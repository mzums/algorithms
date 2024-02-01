#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int a, b, w;
};
constexpr int MAXN = 1e6+7;
int rep[MAXN];
Edge arr[MAXN];
vector<Edge> dowziecia;

int Find(int x) {
    if (rep[x] == x) return x;
    rep[x] = Find(rep[x]);
    return rep[x];
}

bool Union(int a, int b) {
    int x = Find(a);
    int y = Find(b);
    if (x == y) return 0;
    rep[y] = x;
    return 1;
}

bool Sort(Edge a, Edge b) {
    return a.w < b.w;
}

bool czysienieda(int n, int m, int k, int how_many) {
    for (int i = how_many; i <= m; i++)
        Union(arr[i].a, arr[i].b);
    for (int i = 1; i < how_many; i++)
        if (Union(arr[i].a, arr[i].b)) {
            dowziecia.push_back(arr[i]);
            --k;
        }
    if (k < 0) return 1;
    for (int i = 1; i <= n; i++) rep[i] = i;
    for (int i = 0; i < dowziecia.size(); i++)
        Union(dowziecia[i].a, dowziecia[i].b);
    for (int i = 1; i <= m; i++) {
        if (arr[i].w == 0 && k == 0) continue;
        if (Union(arr[i].a, arr[i].b)) {
            dowziecia.push_back(arr[i]);
            if (arr[i].w == 0) --k;
        }
    }
    for (int i = 2; i <= n; i++)
        if (Find(i) != Find(i-1)) return 1;
    if (k != 0) return 1;

    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, how_many = 1;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        cin >> arr[i].a >> arr[i].b >> arr[i].w;
        if(arr[i].w == 0) how_many++;
    }
    for(int i = 1; i <= n; i++) rep[i] = i;
    sort(arr+1, arr+m+1, Sort);

    if (czysienieda(n, m, k, how_many)) {
        cout << "NIE";
        return 0;
    }
    cout << "TAK" << '\n';
    for (auto [a, b, w] : dowziecia)
        cout << a << ' ' << b << ' ' << w << '\n';
}