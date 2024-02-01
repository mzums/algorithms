#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Member {
    int a, b, c, no;
};

const int MAXN = 150007;
bool del[MAXN];
vector <Member> one, two, three;

bool sort_a(Member x, Member y) {
    return x.a > y.a;
}
bool sort_b(Member x, Member y) {
    return x.b > y.b;
}
bool sort_c(Member x, Member y) {
    return x.c > y.c;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, c;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        one.push_back({a, b, c, i});
        two.push_back({a, b, c, i});
        three.push_back({a, b, c, i});
    }
    sort(one.begin(), one.end(), sort_a);
    sort(two.begin(), two.end(), sort_b);
    sort(three.begin(), three.end(), sort_c);

    int i=0, j=0, k=0;
    while (i < n && j < n && k < n) {
        if (del[one[i].no]) i++;
        if (del[two[j].no]) j++;
        if (del[three[k].no]) k++;

        if (one[i].a <= two[j].a || one[i].a <= three[k].a)
            del[one[i].no] = true;
        else if (two[j].b <= one[i].b || two[j].b <= three[k].b)
            del[two[j].no] = true;
        else if (three[k].c <= one[i].c || three[k].c <= two[j].c)
            del[three[k].no] = true;
        else {
            cout << one[i].a + two[j].b + three[k].c;
            return 0;
        }
    }
    cout << -1;
}