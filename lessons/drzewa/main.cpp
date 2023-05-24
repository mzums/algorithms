#include <iostream>
using namespace std;

const int MAXN = 1e6+7;
int b[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str;
    int n, x, y;
    cin >> str >> n;
    str = " " + str;

    for (int i = 1; i < str.length(); i++) {
        if (str[i] == 'b') b[i]++;
        b[i] += b[i-1];
    }
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        cout << b[y] - b[x-1] << "\n";
    }
} 