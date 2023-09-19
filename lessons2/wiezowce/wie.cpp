#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>
#include "wiezaw.h"
using namespace std;
typedef long long ll;

ll bs(int k, ll l){
    ll r = 1e18+7, mid;
    while (l < r) {
        mid = (l+r)/2;
        bool check =  zamowienie(k, mid);
        if(check) l = mid+1;
        else r = mid;
    }
    return l-1;
}

int main(){
    int i, n = wezN();
    ll maxx = 0, x;
    vector<int> order(n);
    for(i=0;i<n;++i) order[i]=i+1;
    std::random_shuffle(order.begin(), order.end());
    for(int i : order){
        if (!zamowienie(i, maxx+1)) continue;
        if (bs(i, maxx+1) >= maxx) {
            maxx = max(maxx, bs(i, maxx+1));
            x = i;
        }
    }
    if (zamowienie(x, 1000000000000000000)) {
        odpowiedz(1000000000000000000);
        return 0;
    }
    cout << maxx;
    odpowiedz(maxx);
}