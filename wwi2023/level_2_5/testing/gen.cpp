#include <iostream>
#include <random>
using namespace std;

int main() { //mt19937
    int seed;
    cin >>seed;
    mt19937 gen(seed);
    cout << gen() << " " << gen()%10;
}