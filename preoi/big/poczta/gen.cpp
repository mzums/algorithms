#include <iostream>
#include <random>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    random_device rd;
    mt19937 gen(rd());

    //uniform_int_distribution<int> dis(1, 1000);
    //int n = dis(gen);
    int n = 1;
    uniform_int_distribution<int> dis2(0, 1000000);
    int h = dis2(gen);
    cout << n << " " << h << "\n";

    for (int i = 0; i < n; ++i) {
        uniform_int_distribution<int> dis3(1, 20);
        int k = dis3(gen);
        cout << k << " ";
        for (int i = 0; i < k; ++i) {
            uniform_int_distribution<int> dis4(-100, 100);
            int a = dis4(gen);
            cout << a << " ";
        }
        cout << "\n";
    }
}