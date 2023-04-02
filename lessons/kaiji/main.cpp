#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string str1, str2;
    int a, b, kaiji=0, opponent=0;
    cin >> str1 >> str2;
    for (int i = 0; i < str1.length(); i+=2) {
        a = str1[i] + str1[i+1];
        b = str2[i] + str2[i+1];
        if (a == 116 && b == 184) kaiji++;
        else if (a == 184 && b == 81) kaiji++;
        else if (a == 81 && b == 116) kaiji++;
        else if (b == 116 && a == 184) opponent++;
        else if (b == 184 && a == 81) opponent++;
        else if (b == 81 && a == 116) opponent++;
    }
    if (kaiji > opponent) cout << "WYGRANA";
    else if (kaiji < opponent) cout << "PRZEGRANA";
    else cout << "REMIS";
}
//116-8<, 184-[], 81-()