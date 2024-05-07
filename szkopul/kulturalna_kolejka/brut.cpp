#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string str;
    cin >> n >> str;
    int i = 0;
    while (1) {
        bool finished = 1;
        for (int j = 0; j < n; j++) {
            if (str[j] == 'X' && j == n-1) {
                finished = 0;
                str[j] = '.';
            }
            else if (str[j] == 'X' && str[j+1] == '.') {
                finished = 0;
                str[j] = '.';
                str[j+1] = 'X';
                j++;
            }
        }
        if (finished) {
            cout << i << "\n";
            break;
        }
        ++i;
    }
}