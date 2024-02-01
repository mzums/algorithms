#include <iostream>
#include <random>
using namespace std;

int main() {
    // Inicjalizacja generatora liczb losowych
    random_device rd;
    mt19937 gen(rd());

    // Wygenerowanie losowych liczb n i m
    uniform_int_distribution<int> dis(1, 10);
    int t = dis(gen);
    cout << t << "\n";

    // Wygenerowanie losowej liczby w zakresie (1, n)
    uniform_int_distribution<int> dis2(1, t);
    uniform_int_distribution<int> dis3(-100, 100);

    // Wyświetlenie wygenerowanych liczb
    for (int i = 0; i < t; i++) {
        int n = dis2(gen);
        cout << n << "\n";
        for (int i = 0; i < n; ++i) {
            int b = dis3(gen);
            cout << b << " ";
        }
        cout << "\n";
    }
}
