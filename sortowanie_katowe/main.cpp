#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct point {
    int x, y;
    double angle;
};

int n;
const int MAXN = 1e6+7;
point arr[MAXN];

bool Sort(point a, point b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool Sort2(point a, point b) {
    if (a.angle != b.angle) return a.angle < b.angle;
    return (pow(a.x - arr[0].x, 2) + pow(a.y - arr[0].y, 2)) <
           (pow(b.x - arr[0].x, 2) + pow(b.y - arr[0].y, 2));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].x >> arr[i].y;

    sort(arr, arr+n, Sort);
    for (int i = 1; i < n; i++)
        arr[i].angle = atan2((arr[i].y-arr[0].y), (arr[i].x-arr[0].x)) * 180 / M_PI;
    
    sort(arr+1, arr+n, Sort2);
    for (int i = 0; i < n; i++)
        cout << arr[i].x << " " << arr[i].y << "\n";
}