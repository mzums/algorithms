#include <iostream>
using namespace std;

constexpr int MAXN = 2e5+7;
int pref[MAXN];
string str;
int k;

bool check(int d) {
    if (d > str.size()-1) return false;
    for (int i = 1; i < str.size()-d; ++i)
        if (pref[i+d] - pref[i-1] >= k) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> str >> k;
    str = ' ' + str;
    for (int i = 1; i < str.size(); ++i)
        pref[i] = pref[i-1] + (str[i] == 'X');

    int l = 0, r = str.size()-1, mid;
    while (l < r) {
        mid = (l+r)/2;
        if (check(mid)) r = mid;
        else l = mid+1;
    }
    cout << (double)r/2 << "\n";
}