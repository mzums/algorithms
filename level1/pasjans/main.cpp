#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n, karta, b, nr;
string out;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    map<int, int> cards;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> karta;
        auto znal = cards.upper_bound(karta);
        if (znal == cards.end()) {
            out += "1\n";
            cards[karta] = ++nr;
        }
        else {
            b = (*znal).second;
            cards.erase(znal);
            cards[karta] = b;
            out += ("2 " + to_string(b) + "\n");
        }
    }
    cout << nr << '\n' << out;
}