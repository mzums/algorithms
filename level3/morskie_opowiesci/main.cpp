#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Trip {
    int dest, dist, no;
};

constexpr int MAXN = 10007, MAXK = 1e6+7, INF = 1e9+7;
int dist[MAXN];
bool ans[MAXK];
vector<int> G[MAXN];
vector<Trip> trips[MAXK];

void dijkstra(int start, int n) {
    for (int i = 1; i <= 2*n; i++) dist[i] = -1;

    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : G[v])
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
    }
}

void printStringWithPutchar(const char *str) {
    while (*str != '\0') {
        putchar(*str);
        str++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n=0, m=0, k=0, a, b, c;
    char znak;
    while ((znak = getchar()) != '\n' && znak != ' ')
        n = n * 10 + (znak - '0');
    while ((znak = getchar()) != '\n' && znak != ' ')
        m = m * 10 + (znak - '0');
    while ((znak = getchar()) != '\n' && znak != ' ')
        k = k * 10 + (znak - '0');

    for (int i = 0; i < m; ++i) {
        a = 0; b = 0;
        while ((znak = getchar()) != '\n' && znak != ' ')
            a = a * 10 + (znak - '0');
        while ((znak = getchar()) != '\n' && znak != ' ')
            b = b * 10 + (znak - '0');
        G[a+n].push_back(b);
        G[a].push_back(b+n);
        G[b+n].push_back(a);
        G[b].push_back(a+n);
    }
    for (int i = 1; i <= k; i++) {
        a = 0; b = 0; c = 0;
        while ((znak = getchar()) != '\n' && znak != ' ')
            a = a * 10 + (znak - '0');
        while ((znak = getchar()) != '\n' && znak != ' ')
            b = b * 10 + (znak - '0');
        while ((znak = getchar()) != '\n' && znak != ' ')
            c = c * 10 + (znak - '0');
        trips[a].push_back({b, c, i});
    }
    for (int i = 1; i <= n; ++i)
        if (trips[i].size() > 0 && G[i].size() > 0) {
            dijkstra(i, n);
            for (auto trip : trips[i]) {
                if (dist[trip.dest + ((trip.dist%2==0) ? 0 : 1) *n] != -1)
                    if (dist[trip.dest + ((trip.dist%2==0) ? 0 : 1) *n] <= trip.dist)
                        ans[trip.no] = true;
            }
        }
    for (int i = 1; i <= k; i++)
        if (ans[i]) printStringWithPutchar("TAK\n");
        else printStringWithPutchar("NIE\n");
}