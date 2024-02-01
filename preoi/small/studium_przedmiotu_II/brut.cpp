#include <iostream>
#include <vector>
#include <algorithm>
#include "stu2lib.h"
using namespace std;

constexpr int MAXN = 2e5+7;
int arr2[MAXN];
int n;

void inicjuj(vector<int> arr) {
    n = arr.size();
    for (int i = 1; i <= n; ++i) {
        arr2[i] = arr[i-1];
    }
}

int odpowiedz(int a, int b) {
    int visited[MAXN];
    for (int i = 0; i <= n; ++i) visited[i] = 0;
    for (int i = a; i <= b; ++i) {
        visited[arr2[i]] = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) return i;
    }
    return n;
}

void zamien(int a, int b) {
    swap(arr2[a], arr2[b]);
}

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
