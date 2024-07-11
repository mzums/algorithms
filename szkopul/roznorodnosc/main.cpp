#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAXN = 1e6+7;
int arr[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, res = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> arr[i];
    }
    arr[0] = -10;
    sort(arr+1, arr+n+1);
    for (int i = 1; i <= n; ++i) {
    	if (arr[i] - arr[i-1] > 1) {
		--arr[i];	
	}
	else if (arr[i] == arr[i-1] && arr[i] != arr[i+1]) {
		++arr[i];
	}
    }
    for (int i = 1; i <= n; ++i) {
    	if (arr[i] != arr[i-1]) ++res;
    }
    cout << res << "\n";
}
