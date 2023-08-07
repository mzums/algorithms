#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e4+7;
double arr[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        double j=0, a=0, b=0;
        while (str[j] != '/') {
            a = 10 * a + str[j]-48;
            j++;
        }
        ++j;
        while (j < str.length()) {
            b = 10 * b + str[j]-48;
            ++j;
        }
        arr[i] = a/b;
    }
    sort(arr, arr+n);
    (arr[0] + arr[1] > arr[n-1]) ? (cout << "TAK") : (cout << "NIE");
}