#include <iostream>
#include "jas.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = init();
    bool switched[n];
    int order[n];

    for (int i = 0; i < n; ++i) {
        switched[i] = false;
        order[i] = i;
        if (wyprobuj(switched) == i) {
            switched[i] ^= 1;
        }
    }
    odpowiedz(switched, order);
}