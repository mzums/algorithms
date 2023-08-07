#include <iostream>
#include <cmath>
using namespace std;

void solve(string a) {
    int x=0, c=0, y=0;
    cout << a << " ";
    for (int i = 0; i < a.length(); i++)
        x += pow(a[i]-48, 2);
    if (a == "1" || a == "4") return;
    cout << x << " ";
    while (x!=1 && x!=4) {
        y = 0;
        for (int i = 0; i < to_string(x).length(); i++)
            y += pow(to_string(x)[i]-48, 2);
        cout << y << " ";
        x = y;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    string a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        solve(a);
        cout << "\n";
    }
}