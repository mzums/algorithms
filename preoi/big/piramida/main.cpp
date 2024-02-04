#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int MAXN = 2007;
int M[MAXN][MAXN];

bool checkSort(int n) {
    for (int i = 1; i < n; ++i){
        if (M[0][i-1] > M[0][i]) return false;
    }
    return true;
}

bool check01(int n) {
    for (int i = 0; i < n; ++i){
        if (M[0][i] != 0 && M[0][i] != 1) return false;
    }
    return true;
}

bool check012(int n) {
    for (int i = 1; i < n; ++i){
        if (M[0][i] == M[0][i-1]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, first0=1e9, first1=1e9;
    cin >> n;
    for (int i = 0; i < 2*n-1; ++i) cin >> M[0][i];
    if (checkSort(2*n-1)) {
        cout << M[0][n-1] << "\n";
        return 0;
    }
    else if (check01(2*n-1)) {
        for (int i = n; i < 2*n-1; ++i) {
            if (M[0][i] == M[0][i-1] && M[0][i] == 0) {
                first0 = i-(n-1);
                break;
            }
            else if (M[0][i] == M[0][i-1] == 1) {
                first1 = i-(n-1);
                break;
            }
        }
        for (int i = n-2; i >= 0; --i) {
            if (M[0][i] == M[0][i+1] && M[0][i] == 0) {
                first0 = min((n-1)-i, first0);
            }
            else if (M[0][i] == M[0][i+1] && M[0][i] == 1) {
                first1 = min((n-1)-i, first1);
            }
        }
        if (check012(2*n-1)) {
            cout << M[0][0] << "\n";
        }
        else if (first0 < first1) cout << "0\n";
        else cout << "1\n";
    }
    else {
        for (int i = 1; i < n; ++i) {
            for (int j = i; j < 2*n-1-i; ++j) {
                int arr[3] = {M[i-1][j-1], M[i-1][j], M[i-1][j+1]};
                sort(arr, arr+3);
                M[i][j] = arr[1];
            }
        }
        cout << M[n-1][n-1] << "\n";
    }
}
