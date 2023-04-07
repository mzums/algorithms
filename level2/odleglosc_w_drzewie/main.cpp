#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e6+7;
vector <int> G[MAXN];
bool deleted[MAXN];
int subtree_size[MAXN], number_of_paths_of_given_length[MAXN];
int score;

void count_sizes_of_subtrees(int v, int anc) {
    subtree_size[v] = 1;
    for (int u : G[v])
        if (u != anc and !deleted[u]) {
            count_sizes_of_subtrees(u, v);
            subtree_size[v] += subtree_size[u];
        }
}

int find_centroid (int root) {
    int v = root, anc = 0;
    bool centroid = false;
    count_sizes_of_subtrees(v, 0);
    while (!centroid) {
        centroid = true;
        for (int u : G[v])
            if (u != anc && !deleted[u] && subtree_size[u]*2 > subtree_size[root]) {
                centroid = false;
                anc = v;
                v = u;
                break;
            }
    }
    return v;
}

void dfs0 (int v, int anc, int depth, int k) {
    score += number_of_paths_of_given_length[k-depth];
    for (int u : G[v])
        if (u != anc && !deleted[u] && depth+1 <= k)
            dfs0(u, v, depth+1, k);
}

void dfs1 (int v, int anc, int depth, int k) {
    number_of_paths_of_given_length[depth]++;
    for (int u : G[v])
        if (u != anc && !deleted[u] && depth+1 <= k)
            dfs1(u, v, depth+1, k);
}

void dfs2 (int v, int anc, int depth, int k) {
    number_of_paths_of_given_length[depth]--;
    for (int u : G[v])
        if (u != anc && !deleted[u] && depth+1 <= k)
            dfs2(u, v, depth+1, k);
}

void count_paths_going_through_v_of_length_k (int v, int k) {
    number_of_paths_of_given_length[0] = 1;
    for (int u : G[v])
        if (!deleted[u]) {
            dfs0(u, v, 1, k);
            dfs1(u, v, 1, k);
        }
    for (int u : G[v])
        if (!deleted[u]) dfs2(u, v, 1, k);
}

void decomposition (int v, int k) {
    int centroid = find_centroid(v);
    count_paths_going_through_v_of_length_k(centroid, k);
    deleted[centroid] = true;
    for (int u : G[centroid])
        if (!deleted[u]) decomposition(u, k);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k, a, b;
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    decomposition(1, k);
    cout << score;
}