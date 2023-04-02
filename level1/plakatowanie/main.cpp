#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    stack <int> s;
    int n, w, h, score=0;
    s.push(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w >> h;
        while (s.top() > h) s.pop();
        if (s.top() < h) {
            score++;
            s.push(h);
        }
    }
    cout << score;
}