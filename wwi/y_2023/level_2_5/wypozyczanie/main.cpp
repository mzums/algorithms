#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a;
const int MAXN = 5*1e5+7;
int bud[MAXN], prices[MAXN];

bool check(int x, int a){
    for(int i=0; i<x; i++){
        if(bud[i] < prices[m-x+i]) a -= prices[m-x+i] - bud[i];
        if(a < 0) return 0;
    }
    return 1;
}

int bs(int l, int r, int a){
    int mid;
    while(l + 1 < r){
        mid = (l + r)/2;
        if (check(mid, a)) l = mid;
        else r = mid;
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> a;
    for(int i=0; i<n; i++) cin >> bud[i];
    for(int i=0; i<m; i++) cin >> prices[i];
    sort(prices, prices+m, std::greater<>());
    sort(bud, bud+n, std::greater<>());
    cout << bs(0, min(n, m)+1, a);
} 