#include <bits/stdc++.h>
using namespace std;

const int base = 1048576;
int tree[2*base+7];
int n, k, v, a, b, res;
char op;
string str;

void upd(int a, int b) {
    a += base - 1;
    b += base + 1;
    while (a/2 != b/2) {
        if (a%2==0) tree[a+1]++;
        if (b%2==1) tree[b-1]++;
        a /= 2;
        b /= 2;
    }
}

int query(int v) {
    res = 0;
    v += base;
    while (v > 0) {
        res += tree[v];
        v /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    cin >> str;
    for (int i = 0; i < n; i++)
        if (str[i] == 'x')
            tree[base+i] = 1;

    for (int i = 0; i < k; i++) {
        cin >> op;
        if (op == 'Q') {
            cin >> v;
            if (query(--v)%2 == 0) cout << "ON\n";
            else cout << "OFF\n";
        }
        else {
            cin >> a >> b;
            upd(--a, --b);
        }
    }
}