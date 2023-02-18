/*#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

const int MAXN = 1007;
pair<double, double> arr[MAXN];
vector <int> G[MAXN];
bool visited[MAXN];
double n, p, s, x, y;
double maxDist;

void dfs(int v) {
    visited[v] = true;
    for (auto u : G[v])
        if(!visited[u]) {
            x = abs(arr[v].first - arr[(int)p-1].first);
            y = abs(arr[v].second - arr[(int)p-1].second);
            maxDist = max(maxDist, (double)(sqrt(pow(x, 2) + pow(y, 2))));
            dfs(u);
        }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> p >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            x = abs(arr[i].first - arr[j].first);
            y = abs(arr[i].second - arr[j].second);
            if (sqrt(pow(x, 2) + pow(y, 2)) <= s) G[i].push_back(j);
        }
    dfs(p-1);
    cout << fixed << setprecision(3) << maxDist + s;
}*/
#include<bits/stdc++.h>
using namespace std;

int n,p,s,maxn=0;
struct node {
    int x;
    int y;
};
pair<int, int> a[1005];

int dist(int i,int j) {
    return max(abs(a[i].first-a[j].first),abs(a[i].second-a[j].second));
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    return dist(p,(int)a)<dist(p,b);
}

int main() {
    cin>>n>>p>>s;
    for(int i=0;i<n;i++) {
        cin>>a[i].first>>a[i].second;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++) {
        if(dist(p,i)<=s) {
            maxn=max(dist(p,i),maxn);
            for(int j=i+1;j<n;j++) {
                if(dist(i,j)<=s) {
                    maxn=max(dist(j,i),maxn);
                    p=j;
                } else break;
            }
            break;
        }
    }
    cout<<maxn<<endl;
    return 0;
}