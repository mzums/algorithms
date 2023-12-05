#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

constexpr int MAXN = 1e6+7;
constexpr ll INF = 1e18+7;
vector <pair<int, int>> G[MAXN];
ll dist[MAXN];

void printStringWithPutchar(const char *str) {
    while (*str != '\0') {
        putchar(*str);
        str++;
    }
}

void print_long(ll value) {
    if(value != 0) {
        print_long(value/10);
        putchar((value%10) + '0');
    }
}

void answer(int n) {
    ll maxx = -1;
    int no = -1;
    vector <int> ans;
    for (int i = 1; i <= n; ++i)
        if (dist[i] + dist[i+n] >= maxx && max(dist[i], dist[i+n]) < 1e18 && dist[i] != dist[i+n])
            maxx = dist[i] + dist[i+n];
    for (int i = 1; i <= n; ++i)
        if (dist[i] + dist[i+n] >= maxx && max(dist[i], dist[i+n]) < 1e18 && dist[i] != dist[i+n]) {
            ans.push_back(i);
            maxx = dist[i] + dist[i+n];
        }
    if (ans.empty()) printStringWithPutchar("BRAK");
    else {
        for (int a : ans) {
            print_long(a);
            putchar(' ');
        }
        putchar('\n');
        print_long((dist[ans[0]] + dist[ans[0]+n]));
    }
}

void dijkstra(int v, int n) {
    for (int i = 0; i <= 2*n; ++i) dist[i] = INF;
    priority_queue <pair<ll, int>> q;
    q.push({0, v});
    while (!q.empty()) {
        v = q.top().second;
        ll d = q.top().first;
        q.pop();
        if (-d >= dist[v]) continue;
        dist[v] = -d;
        for (int i = 0; i < G[v].size(); ++i) {
            int u = G[v][i].first;
            q.push({-(dist[v]+G[v][i].second), u});
        }
    }
    answer(n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n=0, m=0, a, b, c;
    char znak;
    while ((znak = getchar()) != '\n' && znak != ' ')
        n = n * 10 + (znak - '0');
    while ((znak = getchar()) != '\n' && znak != ' ')
        m = m * 10 + (znak - '0');
    for (int i = 0; i < m; i++) {
        a = 0; b = 0; c = 0;
        while ((znak = getchar()) != '\n' && znak != ' ')
            a = a * 10 + (znak - '0');
        while ((znak = getchar()) != '\n' && znak != ' ')
            b = b * 10 + (znak - '0');
        while ((znak = getchar()) != '\n' && znak != ' ')
            c = c * 10 + (znak - '0');
        if (c % 2 == 0) {
            G[a].push_back({b, c});
            G[b].push_back({a, c});
            G[a+n].push_back({b+n, c});
            G[b+n].push_back({a+n, c});
        }
        else {
            G[a+n].push_back({b, c});
            G[b].push_back({a+n, c});
            G[a].push_back({b+n, c});
            G[b+n].push_back({a, c});
        }
    }
    dijkstra(1, n);
}
