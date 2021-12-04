#include <iostream>

std::string oct;

int main() {
  std::cin >> oct;

  for (int i = 0; i < oct.size(); i++) {
    if (oct[i] == '0') {
      if (i == 0)
        std::cout << '0';
      else
        std::cout << "000";
    } else if (oct[i] == '1') {
      if (i == 0)
        std::cout << "1";
      else
        std::cout << "001";
    } else if (oct[i] == '2') {
      if (i == 0)
        std::cout << "10";
      else
        std::cout << "010";
    } else if (oct[i] == '3') {
      if (i == 0)
        std::cout << "11";
      else
        std::cout << "011";
    } else if (oct[i] == '4')
      std::cout << "100";
    else if (oct[i] == '5')
      std::cout << "101";
    else if (oct[i] == '6')
      std::cout << "110";
    else if (oct[i] == '7')
      std::cout << "111";
  }
}