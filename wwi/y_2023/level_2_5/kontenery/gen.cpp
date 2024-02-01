#include <iostream>
#include <random>
using namespace std;

int main() {
    // Inicjalizacja generatora liczb losowych
    random_device rd;
    mt19937 gen(rd());

    // Wygenerowanie losowych liczb n i k
    uniform_int_distribution<int> dis(1, 350);
    int n = dis(gen);
    int k = dis(gen);
    cout << n << " " << k << "\n";

    // Wygenerowanie losowej liczby w zakresie (1, n)
    uniform_int_distribution<int> dis2(1, n);
    uniform_int_distribution<int> dis3(1, n);

    // Wyświetlenie wygenerowanych liczb
    for (int i = 0; i < k; i++) {
        int a = dis2(gen);
        uniform_int_distribution<int> dis3(a, n);
        int l = dis3(gen);
        int d = dis2(gen);
        cout << a << " " << l << " " << d << "\n";
    }

    return 0;
}
