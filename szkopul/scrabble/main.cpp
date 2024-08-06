#include <iostream>
#include <cmath>
using namespace std;

int cnt[30];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.size();
    int m = str2.size();

    int r = 0, l = 0;
    long long res = 0;
    for (int i = 0; i < m; ++i) cnt[int(str2[i] - 'a')]++;
    while (cnt[str1[l] - 'a'] == 0) l++;
    cnt[int(str1[l] - 'a')]--;
    r = l;

    for (l; l < n; ++l) {
        while (r < n-1 && cnt[int(str1[r+1] - 'a')] > 0) {
            cnt[int(str1[r+1] - 'a')]--;
            r++;
        }
        if (r-l+1 >= m/2) {
            res+=r-l+2-ceil(double(m)/2.0);
        }
        cnt[int(str1[l] - 'a')]++;
    }
    cout << res << "\n";
}