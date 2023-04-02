#include <iostream>
#include <stack>
using namespace std;

int arr[100007];

bool check(int n, int x) {
    int score = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == x) score++;
    return score > n/2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, value=0, size=0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (size == 0) {
            value = arr[i];
            size = 1;
        }
        else if (arr[i] != value) size--;
        else size++;
    }
    if (check(n, value)) cout << value;
    else cout << "NIE";
}