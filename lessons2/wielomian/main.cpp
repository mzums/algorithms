#include <iostream>
#include <iomanip>
using namespace std;

double arr[7];

double check(double x) {
    double a = arr[0];
    for (int i = 1; i <= 5; i++)
        a = x * a + arr[i];
    return a;
}

double bs() {
    double l=-100, r=100;
    double mid = (l + r) / 2;
    while (abs(check(mid)) > 0.000001) {
        if (check(l) * check(mid) < 0) r = mid;
        else l = mid;
        mid = (l + r) / 2;
    }
    return mid;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i <= 5; i++) cin >> arr[i];
    cout << fixed << setprecision(6) << bs();
}