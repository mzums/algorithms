#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Member {
    int a, b, c, no;
};

vector <Member> one, two, three;

bool sort_a(Member x, Member y) {
    return x.a < y.a;
}
bool sort_b(Member x, Member y) {
    return x.b < y.b;
}
bool sort_c(Member x, Member y) {
    return x.c < y.c;
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

    while (!one.empty() && !two.empty() && !three.empty()) {
        if (one.back().no == two.back().no && one.back().no == three.back().no) {
            one.pop_back();
            two.pop_back();
            three.pop_back();
        }
        if (one.back().no == two.back().no) {
            one.pop_back();
            two.pop_back();
        }
        else if (two.back().no == three.back().no) {
            two.pop_back();
            three.pop_back();
        }
        else if (one.back().no == three.back().no) {
            one.pop_back();
            three.pop_back();
        }
        else if (one.back().no == 0 || two.back().no == 0 || three.back().no == 0) {
            break;
        }
        else {
            cout << one.back().a + two.back().b + three.back().c;
            cout << "\n" << one.back().no << two.back().no << three.back().no;
            return 0;
        }
    }
    cout << -1;
}