#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e6+7;
bool visited[MAXN];
vector <int> G[MAXN];
int n, m, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
}