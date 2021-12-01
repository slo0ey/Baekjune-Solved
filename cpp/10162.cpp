#include <iostream>

int main() {
  int T;
  int A, B, C;
  std::cin >> T;

  if (T % 10 != 0)
    std::cout << "-1";
  else {
    while (T != 0) {
      if (T >= 300) {
        T -= 300;
        A++;
      } else if (T >= 60) {
        T -= 60;
        B++;
      } else {
        T -= 10;
        C++;
      }
    }
    std::cout << A << " " << B << " " << C;
  }
}