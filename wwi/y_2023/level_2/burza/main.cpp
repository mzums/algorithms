#include <iostream>
#include <algorithm>

typedef long long ll;
using namespace std;

const int BASE = 1048576;
const ll MIN = -1e18 - 7;

struct Node {
    ll value;
    int index;
};

Node tree[2 * BASE + 7];

Node maxx(Node a, Node b) {
    if (a.value > b.value)
        return a;
    if (b.value > a.value)
        return b;
    if (a.index < b.index)
        return a;
    return b;
}

void upd(int a) {
    a /= 2;
    while (a > 0) {
        tree[a] = maxx(tree[2 * a], tree[2 * a + 1]);
        a /= 2;
    }
}

Node query(int a, int b) {
    Node maxVal = {MIN, -1};
    a += BASE - 1;
    b += BASE - 1;
    while (a <= b) {
        if (a % 2 == 1) {
            maxVal = maxx(maxVal, tree[a]);
            ++a;
        }
        if (b % 2 == 0) {
            maxVal = maxx(maxVal, tree[b]);
            --b;
        }
        a >>= 1;
        b >>= 1;
    }
    return maxVal;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q, a, b, c;
    string op;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> tree[BASE + i].value;
        tree[BASE + i].index = i;
    }
    for (int i = BASE - 1; i > 0; i--)
        tree[i] = maxx(tree[2 * i], tree[2 * i + 1]);

    for (int i = 0; i < q; i++) {
        cin >> op;
        if (op == "WZROST") {
            cin >> a >> b;
            tree[BASE + a - 1].value += b;
            upd(BASE + a - 1);
            cout << tree[BASE + a - 1].value << "\n";
        } else {
            cin >> a >> b >> c;
            Node result = query(a, b);
            tree[BASE + result.index].value = max(tree[BASE + result.index].value - c, (ll)0);
            upd(BASE + result.index);
            cout << result.index + 1 << " " << tree[BASE + result.index].value << "\n";
        }
    }
}