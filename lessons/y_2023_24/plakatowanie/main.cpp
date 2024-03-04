#include <iostream>
#include <stack>
using namespace std;

constexpr int MAXN = 25e4+7;
int arr[MAXN];
stack<int> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, w, res=0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> w >> arr[i];
        while (!s.empty() && arr[i] < s.top()) s.pop();
        if (s.empty() || s.top() < arr[i]) {
            s.push(arr[i]);
            ++res;
        }
    }
    cout << res;
}