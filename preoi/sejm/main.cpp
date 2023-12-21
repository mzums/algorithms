#include <vector>
#include <algorithm>
#include "sejlib.h"
using namespace std;

vector<int> one, two;
vector<pair<int, int>> pos;

int main() {
    int n = init();
    for (int i = 2; i <= n; ++i)
        pos.push_back({wywiad(i, 1), i});

    sort(pos.begin(), pos.end());
    int correct = pos[0].first, maxx = 1, cnt = 1;
    for (int i = 1; i < n-1; ++i) {
        if (pos[i].first == pos[i-1].first) ++cnt;
        else cnt = 1;
        if (cnt > maxx) {
            maxx = cnt;
            correct = pos[i-1].first;
        }
    }
    for (auto [a, b] : pos) {
        if (a == correct) one.push_back(b);
        else two.push_back(b);
    }
    if (wywiad(1, n) == wywiad(one[0], n))
        one.push_back(1);
    else
        two.push_back(1);

    if (one.size() < two.size()) {
        sort(one.begin(), one.end());
        odpowiedz(one);
    }
    else {
        sort(two.begin(), two.end());
        odpowiedz(two);
    }
}