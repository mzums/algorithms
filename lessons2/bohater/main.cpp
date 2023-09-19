#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Fight {
    int a, b, no;
};

vector <Fight> pluss, minuss;
vector <int> ans;

bool sort_p(Fight one, Fight two) {
    if (one.a != two.a)
        return one.a < two.a;
    return one.b > two.b;
}

bool sort_m(Fight one, Fight two) {
    if (one.b != two.b)
        return one.b > two.b;
    return one.a < two.a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, a, b, curr=0;
    long long z;
    cin >> n >> z;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        if (b-a > 0) pluss.push_back({a, b, i});
        else minuss.push_back({a, b, i});
    }
    sort(pluss.begin(), pluss.end(), sort_p);
    for (auto i : pluss) {
        ans.push_back(i.no);
        z -= i.a;
        if (z <= 0) {
            cout << "NIE";
            return 0;
        }
        z += i.b;
    }
    sort(minuss.begin(), minuss.end(), sort_m);
    for (auto i : minuss) {
        ans.push_back(i.no);
        z -= i.a;
        if (z <= 0) {
            cout << "NIE";
            return 0;
        }
        z += i.b;
    }
    cout << "TAK\n";
    for (auto i : ans) cout << i << " ";
}