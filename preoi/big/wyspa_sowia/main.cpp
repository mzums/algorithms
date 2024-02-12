#include <iostream>
using namespace std;

constexpr int MAXN = 1007;
int dp[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, maxx = 0, no = 0, check = 1;
    string str, str2 = "";
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> str;
        str = ' ' + str;
        for (int j = 1; j <= m; ++j) {
            if (str[j] == 'S') dp[j] = dp[j-1] + 1;
            else dp[j] = 0;
            if (dp[j] == maxx) {
                check = -1;
            }
            if (dp[j] > maxx) {
                maxx = dp[j];
                no = j;
                check = 1;
            }
        }
    }
    for (int i = m; i > 0; --i) {
        if (i == no) {
            for (;i > no-maxx; --i) {
                if (check == 1) str2 += 'S';
                else str2 += 'x';
            }
        }
        if (str[i] == '.') str2 += str[i];
        else str2 += 'x';
    }
    for (int i = m-1; i >= 0; --i) cout << str2[i];
}