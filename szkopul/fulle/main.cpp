#include <iostream>
#include <algorithm>
using namespace std;

int arr[20];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i]-'0' > 1 && str[i]-'0' < 10) arr[str[i]-'0']++;
        else if (str[i] == 'T') arr[10]++;
        else if (str[i] == 'J') arr[11]++;
        else if (str[i] == 'Q') arr[12]++;
        else if (str[i] == 'K') arr[13]++;
        else if (str[i] == 'A') arr[14]++;
    }
    int c2=0, c3=0, c4=0;
    for (int i = 2; i <= 14; ++i) {
        if (arr[i] == 2) c2++;
        else if (arr[i] == 3) c3++;
        else if (arr[i] == 4) c4++;
    }
    int res = 0;
    for (int i = 0; i <= c3; ++i)
        for (int j = 0; j <= c4; ++j)
            res = max(res, min(c2+c3-i+2*(c4-j), i+j));

    cout << res << '\n';
}