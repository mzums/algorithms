#include <iostream>
using namespace std;

const int BASE = 1 << 17;
int arr[BASE+7];
int tree[2*BASE+7][7];

void init() {
    for (int i = BASE; i <= 2*BASE; i++)
        for (int j = 1; j <= 5; j++) 
            tree[i][j] = 1;

    for (int i = BASE-1; i >= 1; i--) {
        for (int j = 1; j <= 5; j++) 
            tree[i][j] = tree[2*i][j] + tree[2*i+1][j];
    }
}

void upd(int x, int layer) {
    while(x > 0) {
        tree[x][layer] = tree[2*x][layer] + tree[2*x+1][layer];
        x /= 2;
    }
}

int query(int a, int b, int c) {
    int res = 0;
    a += BASE - 1;
    b += BASE - 1;
    while (a <= b) {
        if (a % 2 == 1) {
            res += tree[a][c];
            ++a;
        }
        if (b % 2 == 0) {
            res += tree[b][c];
            --b;
        }
        a >>= 1;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();

    string op;
    int n, q, a, b, c, a2;
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        cin >> op;
        if (op == "DODAJ") {
            cin >> a >> b;
            arr[a] += b;
            a2 = a+BASE-1;
            for (int j = 1; j <= 5; j++) {
                if (arr[a] % j == 0) tree[a2][j] = 1;
                else tree[a2][j] = 0;
                upd(a2/2, j);
            }
        }
        else {
            cin >> a >> b >> c;
            cout << query(a, b, c) << "\n";
        }
    }
}
/*
5 8
DODAJ 2 4
DODAJ 5 10
DODAJ 3 4
SKRZYNKI 2 5 1
SKRZYNKI 2 5 1
DODAJ 4 7
SKRZYNKI 2 5 1
SKRZYNKI 2 3 1
*/