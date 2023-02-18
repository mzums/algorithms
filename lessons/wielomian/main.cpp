#include <iostream>
#include <cmath>
using namespace std;

int arr[7];

double check(double x) {
    long long res = 0;
    for (int i = 0; i < 6; i++)
        res += arr[i] * pow(x, 5-i);
    return res;
}

double bs(double l, double r) {
    double mid = (l+r) / 2;
    while (abs(check(mid) > 0.0001)) {
        cout << mid << " ";
        if (check(mid) > 0) r = mid;
        else  l = mid;
        mid = (l+r) / 2;
    }
    cout << "\n";
    return mid;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie();
    
    for (int i = 0; i < 6; i++) cin >> arr[i];
    cout << check(1) << "\n\n";
    cout << bs(-1000.0, 1000.0);
}