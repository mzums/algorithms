#include <iostream>
using namespace std;

string solve(int n) {
    if (n == 0) return "";
    if (n == 1) return "1";
    if (n == 2) return "(1+1)";
    if (n % 2 == 0) return "((1+1)*" + solve(n/2) + ")";
    if (n % 2 == 1) return "(1+" + solve(n-1) + ")";
} 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n;
    while (n--){
        cin >> t;
        cout << solve(t) << '\n';
    }
}