#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 1e6 + 7;
int arr[MAXN];
int n;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++)
        for (int j = 1; j < n-i; j++)
            if (arr[j] < arr[j - 1]) swap(arr[j], arr[j - 1]);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}