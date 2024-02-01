#include<iostream>

using namespace std;

int main() {
    unsigned long long a, b, pot=2, out=0, prev_pot=1;
    bool bit_a, bit_b;

    cin >> a >> b;
    bit_a = a&1;
    bit_b = b&1;
    if (bit_a != bit_b){
        cout << -1;
        return 0;
    }

    while (a != b){
        bit_a = a&pot;
        bit_b = b&pot;
        if (bit_a != bit_b){
            out += prev_pot;
            a ^= prev_pot;
            b += prev_pot;
        }
        pot *= 2;
        prev_pot *= 2;
        if (pot == 9223372036854775808) {
            cout << -1;
            return 0;
        }
    }
    cout << out;
}