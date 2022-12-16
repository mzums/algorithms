#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e6+7;
pair <int, string> arr[MAXN];
int n;
string str;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        arr[i] = {str.length(), str};
    }
    sort(arr, arr+n);
    for (int i = 0; i < n; i++)
        cout << arr[i].second << "\n";
}