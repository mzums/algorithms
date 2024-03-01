#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 4e5+7;
int arr[MAXN];

bool check(int x, int n) {                                                      
    for (int i = x; i <= n-x-1; ++i) {                                          
        if (arr[i] < 2*x+1) continue;                                           
        bool good = true;                                                       
        for (int j = i-x; j <= i+x; ++j)                                        
            if (arr[j] <= x) good = false;                                      
        if (good) return true;                                                  
    }                                                                           
    return false;                                                               
}

int bs(int n) {
    int l = 1, r = n, result = 0;

    while (l < r) {
        int mid = (l + r) / 2;
        if (!check(mid, n)) r = mid - 1;
        else l = mid;
    }
    return l - 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << bs(n);
    cout << check(3, n);
}