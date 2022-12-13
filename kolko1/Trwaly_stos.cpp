#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, x;
    char oper;
    vector<vector<int>> stosy;
    vector<int> stos;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> oper;
        stosy.push_back(stos);
        if (oper == '+') {
            cin >> x;
            stos.push_back(x);
        }
        else if (oper == '-')
            stos.pop_back();
        else if (oper == '*') {
            cin >> x;
            stos = stosy[stosy.size() - x - 1];
        }
        if (stos.size() > 0)
            cout << stos[stos.size() - 1] << "\n";
        else
            cout << "-1\n";
    }
}