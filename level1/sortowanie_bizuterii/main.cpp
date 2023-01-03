#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e6+7;
pair <int, string> arr[MAXN];
string str;
int n;

bool Sort(const pair<int, string> &a, const pair<int, string> &b) {
    if (a.first != b.first)
        return (a.first < b.first);
    return (a.second < b.second);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        arr[i] = make_pair(str.length(), str);
    }
    sort(arr, arr+n, Sort);
    for (int i = 0; i < n; i++)
        cout << arr[i].second << "\n";
}