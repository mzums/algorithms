#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Drink {
    int a, b, no;
};

vector <Drink> pluss, minuss;
vector <int> ans;

bool sort_p(Drink one, Drink two) {
    if (one.a != two.a)
        return one.a < two.a;
    return one.b > two.b;
}

bool sort_m(Drink one, Drink two) {
    if (one.b != two.b)
        return one.b > two.b;
    return one.a < two.a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    long long m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        if (b - a >= 0) pluss.push_back({a, b, i});
        else minuss.push_back({a, b, i});
    }
    sort(pluss.begin(), pluss.end(), sort_p);
    for (auto i : pluss) {
        m -= i.a;
        if (m <= 0) {
            cout << "NIE\n";
            return 0;
        }
        m += i.b;
        ans.push_back(i.no);
    }
    sort(minuss.begin(), minuss.end(), sort_m);
    for (auto i : minuss) {
        m -= i.a;
        if (m <= 0) {
            cout << "NIE\n";
            return 0;
        }
        m += i.b;
        ans.push_back(i.no);
    }
    cout << "TAK\n";
    for (int i : ans) cout << i << " ";
}