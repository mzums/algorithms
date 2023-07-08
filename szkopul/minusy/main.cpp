#include <iostream>
using namespace std;

const int MAXN = 1e6+7;
char arr[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    cin >> arr[0];
    cout << "-";
    for (int i = 1; i < n-1; i++) {
        cin >> arr[i];
        if (arr[i] == '-' && arr[i-1] == '+') cout << ")-";
        else if (arr[i] == '+' && arr[i-1] == '-') cout << "(-";
        else cout << "-";
    }
    if (arr[n-2] == '+') cout << ')';
}