#include <iostream>
#include <map>
#include <vector>

using namespace std;

multimap<double, int> m;
vector<int> G[257];

constexpr double frequencies[] = {
    (8.965 + 1.021) / 100, 1.482 / 100, (3.988 + 0.448) / 100, 3.293 / 100, (7.921 + 1.131) / 100, 
    0.312 / 100, 1.377 / 100, 1.072 / 100, 8.286 / 100, 2.343 / 100, 3.411 / 100,
    (2.136 + 1.746) / 100, 2.911 / 100, (5.600 + 0.185) / 100, (7.590 + 0.823) / 100,
    3.101 / 100, 0.003 / 100, 4.571 / 100, (4.263 + 0.683) / 100, 3.966 / 100, 2.347 / 100,
    0.034 / 100, 4.549 / 100, 0.019 / 100, 3.857 / 100, (5.620 + 0.061 + 0.885) / 100
};

int main() {
    int i;

    for (i = 0; i < 26; i++){
        cout << "Frequency " << fixed << (i) << ": " << frequencies[i] << endl;
    }

    for (int i = 0; i < 26; i++){
        m.insert({frequencies[i], i});
    }
    cout << m.begin()->second << endl;
    int idx = 26;

    while (m.size() > 1){
        int a = m.begin()->second;
        double freqA = m.begin()->first;
        m.erase(m.begin());

        int b = m.begin()->second;
        double freqB = m.begin()->first;
        cout << "a: " << a << " b: " << b << endl;
        m.erase(m.begin());

        m.insert({freqA + freqB, idx});
        G[idx].push_back(a);
        G[idx].push_back(b);
        idx++;
    }

    int lastIdx = idx - 1;
    cout << "Last element: " << m.begin()->second << endl;

    for (int i = 26; i <= lastIdx; i++){
        for (int j = 0; j < G[i].size(); j++) {
            cout << i << " " << G[i][j] << '\n';
        }
    }

    return 0;
}
