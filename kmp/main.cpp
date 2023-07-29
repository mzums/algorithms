#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MAXN = 16*1e6+7;
int ps[MAXN];
string pat, str, temp="$";
ll n, m, i=1, j;

void solve (const string &str, int ps[]) {
    ps[0] = -1;
    ps[1] = 0;
    ll l = 0;
    for (ll i = 2; i < str.size(); i++) {
        while (l >= 0 && str[l+1] != str[i]) l = ps[l];
        l++;
        ps[i] = l;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    cin >> pat >> str;
    str = temp + pat + temp + str;

    solve(str, ps);
    n = str.length();
    m = pat.length();

    for (ll i = m+1; i < str.length(); i++)
        if (ps[i] == pat.length())
            cout << i-(ll)pat.length()-m << "\n";
}