#include <iostream>
using namespace std;

constexpr int MAXN = 1e6+7;
int lps[MAXN], cnt[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string txt;
    cin >> n >> txt;
    txt = '$' + txt;        
    int j = 0;

    for (int i = 2; i <= n; ++i) {
        while (txt[i] != txt[j+1] && j > 0)
            j = lps[j];
        if (txt[i] == txt[j+1]) ++j;
        lps[i] = j;
        cnt[j]++;
    }
    int len = lps[n];
    if (cnt[len] >= 2) {
        cout << len << "\n";
        return 0;
    }
    len = lps[len];
    while (len) {
        if (cnt[len] >= 1) {
            cout << len << "\n";
            return 0;
        }
        else len = lps[len];
    }
    cout << "0\n";
}