#include <iostream> 
using namespace std;
typedef long long ll;

struct Point {
    ll x, y;
};  

int orientation(Point p, Point q, Point r) {
    ll val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // colinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
    return false;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    ll o1 = orientation(p1, q1, p2);
    ll o2 = orientation(p1, q1, q2);
    ll o3 = orientation(p2, q2, p1);
    ll o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4) return true;
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
    return false;
}

int main() {
    ll n;
    scanf ("%lld",&n);  
    for (int i = 0; i < n; i++) {
        Point p1, p2, q1, q2;
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &p1.x, &p1.y, &p2.x, &p2.y, &q1.x, &q1.y, &q2.x, &q2.y);
        if (doIntersect(p1, p2, q1, q2)) printf("TAK\n");
        else printf("NIE\n");
    }
}