#include <math.h>

#include <iostream>
using namespace std;

int main() {
  int D, H, W;
  double rate;
  cin >> D >> H >> W;

  rate = pow(D, 2) / (pow(H, 2) + pow(W, 2));
  rate = sqrt(rate);
  H = H * rate;
  W = W * rate;

  cout << H << " " << W;
}