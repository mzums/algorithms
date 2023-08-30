#include <iostream>
#include <vector>
using namespace std;

int n, dp[305][305];

int main() {
    cin >> n;
    vector<int> colors(n); 
    for (int  i = 0; i < n; i++) cin >> colors[i];

    for (int i = n-1; i >= 0; --i) 
        for (int j = i+1; j < n; ++j) {
            if (colors[i] == colors[j])
                dp[i][j] = max(dp[i][j], 1 + dp[i+1][j-1]);
            for (int k = i+1; k < j; ++k)
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
        }
    cout << n - dp[0][n-1] << "\n";
}
