#include <iostream>
#include <vector>
using namespace std;

constexpr int MAXN = 1e5+7;
vector<int> G[MAXN];
int subtree_size[MAXN];

void dfs(int v, int p) {
    subtree_size[v] = 1;
    for (int u : G[v]) {
        if (u == p) continue;
        dfs(u, v);
        subtree_size[v] += subtree_size[u];
    }
}

vector<int> get_centroid(int v, int p, int n) {
    vector<int> centroids;
    bool is_centroid = true;
    for (int u : G[v]) {
        if (u == p) continue;
        if (subtree_size[u] *2 > n) is_centroid = false;
        vector<int> child_centroids = get_centroid(u, v, n);
        centroids.insert(centroids.end(), child_centroids.begin(), child_centroids.end());
    }
    if (is_centroid && n - subtree_size[v] <= n/2) centroids.push_back(v);
    return centroids;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, 0);
    vector<int> centroids = get_centroid(1, 0, n);
    if (centroids.size() == 1 || G[centroids[0]].size() > G[centroids[1]].size() || (G[centroids[0]].size() == G[centroids[1]].size() && centroids[0] < centroids[1]))
        cout << centroids[0] << '\n' << G[centroids[0]].size() << '\n';
    else
        cout << centroids[1] << '\n' << G[centroids[1]].size() << '\n';
}