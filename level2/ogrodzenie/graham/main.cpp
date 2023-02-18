#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

struct Point {
    int x, y;
    double angle;
};

const int MAXN = 1e6+7;
Point arr[MAXN], p0;
int n, ind, minn=1e9+7;
double circuit;

double getDist(Point p, Point q) {
    return sqrt(pow(p.x - q.x, 2) + pow(p.y - q.y, 2));
}

bool SortAng(Point &a, Point &b) {
    long double angleA = atan2(a.y - arr[0].y, a.x - arr[0].x) * 180 / M_PI;
    long double angleB = atan2(b.y - arr[0].y, b.x - arr[0].x) * 180 / M_PI;
    if (angleA == angleB) {
        long double distA = sqrt(pow(a.x - arr[0].x, 2) + pow(a.y - arr[0].y, 2));
        long double distB = sqrt(pow(b.x - arr[0].x, 2) + pow(b.y - arr[0].y, 2));
        return distA < distB;
    }
    return angleA < angleB;
}

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);  
    if (val == 0) return 0;  // collinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}


double convexHull() {
    sort(arr+1, arr+n, SortAng);
    int m = 1;
    for (int i = 0; i < n; i++) {
        while (i < n-1 && orientation(p0, arr[i], arr[i+1]) == 0) i++;
        arr[m] = arr[i];
        m++;
    }
    cout << arr[0].y;

    if (m < 3) return 0;
    vector <Point> v;
    v.push_back(arr[0]);
    v.push_back(arr[1]);
    circuit += getDist(arr[0], arr[1]);
    v.push_back(arr[2]);
    circuit += getDist(arr[1], arr[2]);

    for (int i = 2; i < m; i++) {
        while (v.size()>1 && orientation(v[v.size()-2], v.back(), arr[i]) != 2) {
            circuit -= getDist(v[v.size()-2], v[v.size()-1]);
            v.pop_back();
        }
        v.push_back(arr[i]);
        circuit += getDist(v[v.size()-1], v[v.size()-2]);
    }
    if (orientation(v[0], v[v.size()-1], v[v.size()-2]) == 2) {
        circuit -= getDist(v[v.size()-2], v[v.size()-1]);
        circuit -= getDist(v[0], v[v.size()-1]);
        circuit += getDist(v[0], v[v.size()-2]);
    }

    circuit += getDist(v[v.size()-1], v[0]);
    return circuit;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
        if (arr[i].y < minn || (arr[i].y == minn && arr[i].x < arr[ind].x)) {
            minn = arr[i].y;
            ind = i;
        }
    }
    swap(arr[ind], arr[0]);
    p0 = arr[0];
    cout << fixed << setprecision(10) << convexHull();
}