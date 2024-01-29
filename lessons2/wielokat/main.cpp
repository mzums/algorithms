#include <iostream>
using namespace std;

struct Vertex {
    long double x, y;
};
constexpr int MAXN = 1e6+7;
Vertex polygon[MAXN], point;

bool isPointOnEdge(Vertex point, Vertex p1, Vertex p2) {
    return ((point.x >= min(p1.x, p2.x)) && (point.x <= max(p1.x, p2.x)) &&
            (point.y >= min(p1.y, p2.y) && point.y <= max(p1.y, p2.y)) &&
            ((point.x - p1.x) * (p2.y - p1.y) == (p2.x - p1.x) * (point.y - p1.y)));
}

string isPointInsidePolygon(Vertex& point, Vertex* polygon, int n) {
    bool inside = false;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (isPointOnEdge(point, polygon[i], polygon[j])) return "KRAWEDZ";
        if (((polygon[i].y > point.y) != (polygon[j].y > point.y)) &&
            (point.x < (polygon[j].x - polygon[i].x) * (point.y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x)) {
            inside = !inside;
        }
    }
    return inside ? "WEWNATRZ" : "NA ZEWNATRZ";
}

int main() {
    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i)
        scanf("%Lf %Lf", &polygon[i].x, &polygon[i].y);

    cin >> m;
    for (int i = 0; i < m; ++i) {
        scanf("%Lf %Lf", &point.x, &point.y);
        printf("%s\n", isPointInsidePolygon(point, polygon, n).c_str());
    }
}