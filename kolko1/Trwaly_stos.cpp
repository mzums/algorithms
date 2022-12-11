#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, a;
char op;

int main() {
    ios_base::sync_with_Stdio(0);
    cin.tie(0); cout.tie(0);

    vector <stack> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == '+') {
            cin >> a;
            v.push_back(v[i]);

        }
    }
}