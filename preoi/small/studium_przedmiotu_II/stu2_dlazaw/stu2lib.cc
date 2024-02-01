#include <bits/stdc++.h>
#include "main.cpp"
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin>>arr[i];
    inicjuj(arr);
    while (q--){
        int a,b;
        bool type;
        cin>>type>>a>>b;
        if (!type) zamien(a,b);
        else cout<<odpowiedz(a,b)<<'\n';
    }
}
