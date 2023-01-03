#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 5007;
pair <int, int> pos[MAXN];
int anc[1250000+7];
int n, score;

struct edge {
    int a;
    int b;
    int dist;
};

int Find(int v) {
    if (v == anc[v])
        return v;
    else {
        anc[v] = Find(anc[v]);
        return anc[v];
    }
}

void Union(int a, int b) {
    Find(a);
    Find(b);
    anc[anc[a]] = anc[b];
}

bool Sort (const edge &e1, const edge &e2) {
    return e1.dist > e2.dist;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    vector <edge> v;
    for (int i = 0; i < n; i++)
        cin >> pos[i].first >> pos[i].second;

    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            v.push_back(edge{i, j, abs(pos[i].first-pos[j].first) + abs(pos[i].second-pos[j].second)});

    for (int i = 1; i <= n; ++i) anc[i] = i;
    sort(v.begin(), v.end(), Sort);

    int i = v.size();
    while (i > 0) {
        edge x = v.back();
        v.pop_back();
        if (Find(x.a) != Find(x.b)) {
            score += x.dist;
            Union(x.a, x.b);
        }
        i--;
    }
    cout << score;
}