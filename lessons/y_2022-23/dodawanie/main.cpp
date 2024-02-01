#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int BASE = 10;

string add(string& s1, string& s2) {
    string res = "";
    int carry = 0;

    int n = s1.size();
    int m = s2.size();
    if (m > n) {
        swap(m, n);
        swap(s1, s2);
    }

    for (int i = s1.size() - 1, j = s2.size() - 1; i >= 0 || j >= 0 || carry; i--, j--) {
        int d1 = (i >= 0 ? s1[i] - '0' : 0);
        int d2 = (j >= 0 ? s2[j] - '0' : 0);
        int sum = d1 + d2 + carry;
        carry = sum / BASE;
        res += (sum % BASE) + '0';
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    string sum = add(s1, s2);
    cout << sum;
}