#include <bits/stdc++.h>
#include "sejlib.h"
using namespace std;

int main() {
    int i;
    int n = init();
    int zap1 = wywiad(1,3);
    int zap2 = wywiad(3,2);
    int zap3 = wywiad(1,3);
    vector<int> wy;
    wy.push_back(3);
    if (zap3 < zap1) wy.push_back(1);
	odpowiedz(wy);
	return 0;
}
