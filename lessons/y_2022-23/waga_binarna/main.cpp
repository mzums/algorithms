#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct weight {
    int value;
    int prec;
    double score;
};
const int MAXN = 1e6+7;
vector<weight> v;
int n;

bool Sort(const weight &a, const weight &b) {
    if (a.score != b.score)
        return a.score < b.score;
    return a.value < b.value;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].value >> v[i].prec;
        v[i].score = v[i].value / pow(2, v[i].prec);
    }
    sort(v.begin(), v.end(), Sort);
    for (int i = 0; i < n; i++)
        cout << v[i].value << " " << v[i].prec << "\n";
}