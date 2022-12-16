#include <iostream>
#include <algorithm>
using namespace std;

int arr[150];
int k, l=1, r=1, score, result, ll, rr, len=1e6+7;
string str;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> str >> k;
    str = " " + str;
    while (r <= str.length()) {
        if (score < k) {
            arr[str[r]]++;
            if (arr[str[r]] == 1) score++;
            r++;
        }
        else {
            result = max(result, score);
            arr[str[l]]--;
            if (arr[str[l]] == 0) score--;
            l++;
        }
        if (r-l+1 < len && score == k) {
            ll = l;
            rr = r-1;
            len = r-l+1;
        }
    }
    if (result < k)
        cout << "BRAK";
    else
        cout << ll << " " << rr << "\n";
}