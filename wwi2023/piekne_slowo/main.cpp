#include <iostream>
using namespace std;

const int MAXN = 1e6+7;
int p[MAXN];

void kmp (const string &str) {
    p[0] = -1;
    int l = 0;
    for (int i = 2; i < str.size(); i++) {
        while (l > 0 && str[l+1] != str[i]) l = p[l];
        if (str[i] == str[l+1]) l++;
        p[i] = l;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str;
    cin >> str;
    str = "$" + str;
    kmp(str);
    for (int i = 1; i < str.size(); i++)
        if (p[i] > 0) cout << 1;
        else cout << 0;
}