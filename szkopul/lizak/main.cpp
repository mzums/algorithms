#include <iostream>
using namespace std;

constexpr int MAXN = 2e6+7;
pair<int, int> arr[MAXN]; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, res=0, l, r, summ, lastw=-1, firstw=-1, a;
    string str;
    cin >> n >> m >> str;
    for (int i = 0; i <= 2*n; i++) arr[i] = {-1, -1};
    for (int i = 0; i < n; i++) {
        if (str[i] == 'T') res += 2;
        else {
            res++;
            lastw = i;
            if (firstw == -1) firstw = i;
        }
    }
    l = 0; r = n-1;
    summ = res;
    while (summ > 0) {
        arr[summ] = {l, r};
        if (str[l] == 'T') l++;
        else if (str[r] == 'T') r--;
        else {
            l++;
            r--;
        }
        summ -= 2;
    }
    if (firstw < n-1-lastw) {
        l = firstw+1;
        r = n-1;
        summ = res - 2*firstw - 1;
    }
    else {
        l = 0;
        r = lastw-1;
        summ = res - 2*(n-1-lastw) - 1;
    }
    while (summ > 0) {
        arr[summ] = {l, r};
        if (str[l] == 'T') l++;
        else if (str[r] == 'T') r--;
        else {
            l++;
            r--;
        }
        summ -= 2;
    }
    for (int i = 0; i < m; i++) {
        cin >> a;
        if (arr[a].first == -1 || arr[a].second < arr[a].first || a > res) {
            cout << "NIE\n";
            continue;
        }
        cout << arr[a].first+1 << " " << arr[a].second+1 << "\n";
    }
}
