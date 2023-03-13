#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double a5, a4, a3, a2, a1, a0;

double check(double x) {
    return a5*pow(x,5) + a4*pow(x,4) + a3*pow(x,3) + a2*pow(x,2) + a1*x + a0;
}

double bs(double l, double r) {
    double mid = (l+r) / 2.0;
    while (abs(check(mid)) > 0.000001) {
        if (check(l) * check(mid) < 0) r = mid;
        else  l = mid;
        mid = (l+r) / 2.0;
    }
    return mid;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie();
    
    cin >> a5 >> a4 >> a3 >> a2 >> a1 >> a0;
    cout << fixed << setprecision(6) << bs(-100.0, 100.0);
}