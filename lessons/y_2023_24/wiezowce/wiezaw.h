#include "wie.h"

namespace wiezaw {

  const int QUERIES = 303030;

  bool initialized = false;

  int n;
  std::vector <long long> H;
  int queries = 0;

  void initialize() {
    initialized = true;
    std::cin >> n;
    for(int i=0; i<n; i++) {
      long long x;
      std::cin >> x;
      H.push_back(x);
    }
  }

  int wezN() {
    if(!initialized) initialize();
    return n;
  }

  bool zamowienie(int i, long long j) {
    if(!initialized) initialize();
    queries++;
    if(queries > QUERIES) {
      std::cout << "za duzo zapytan\n";
      exit(1);
    }
    if(not(1 <= i and i <= n) or not(1 <= j and j <= 1000LL * 1000 * 1000 * 1000 * 1000 * 1000)) {
      std::cout << "niewlasciwe argumenty\n";
      exit(1);
    }
    return H[i-1] >= j;
  }

  void odpowiedz(long long X) {
    if(!initialized) initialize();
    bool ok = (*max_element(H.begin(), H.end()) == X);
    std::cout << (ok ? "OK\n" : "zla odpowiedz\n");
    exit(0);
  }
};

int wezN() {
  return wiezaw::wezN();
}

bool zamowienie(int i, long long j) {
  return wiezaw::zamowienie(i, j);
}

void odpowiedz(long long X) {
  wiezaw::odpowiedz(X);
}
