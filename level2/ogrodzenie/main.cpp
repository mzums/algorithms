#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

struct point {
    int x, y;
};

int n, start;
double score;
point points[500007];

int orientation(point p, point q, point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}
  
double convexHull() {
    if (n < 3) return 0;
    vector<point> hull;
  
    for (int i = 1; i < n; i++)
        if (points[i].x < points[start].x) start = i;
  
    int curr = start, next;
    do {
        hull.push_back(points[curr]);
        next = (curr+1) % n;
        for (int i = 0; i < n; i++)
            if (orientation(points[curr], points[i], points[next]) == 2) next = i;
        curr = next;
    } while (curr != start);

    for (int i = 0; i < hull.size()-1; i++)
        score += sqrt(pow(hull[i].x-hull[i+1].x, 2) + pow(hull[i].y-hull[i+1].y, 2));
    score += sqrt(pow(hull[0].x-hull[hull.size()-1].x, 2) + pow(hull[0].y-hull[hull.size()-1].y, 2));

    return score;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> points[i].x >> points[i].y;
    cout << fixed << setprecision(10) << convexHull();
}