#include <iostream>

int main() {
  char str[10];
  int A, B, C;
  std::cin.getline(str, 10);
  A = str[0] - 48;
  B = str[4] - 48;
  C = str[8] - 48;

  if (A + B == C)
    std::cout << "YES";
  else
    std::cout << "NO";
}