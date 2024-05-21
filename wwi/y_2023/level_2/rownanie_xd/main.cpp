#include <iostream>
using namespace std;

int main() {
    long long a, b, x;
    cin >> a >> b;
    x = (((a-b) / 2) & a);
    if ((a^x) == (b+x)) cout << x << '\n'; 
    else cout << "-1\n";
}