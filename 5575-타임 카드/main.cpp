#include <iostream>

void deserialize(int (&time)[3], int sec) {
  time[0] = sec / 3600;
  time[1] = (sec % 3600) / 60;
  time[2] = ((sec % 3600) % 60);
}

void serialize(int &time, int h, int m, int s) { time = (h * 3600) + (m * 60) + s; }

int main() {
  int h1, m1, s1, h2, m2, s2;
  int T1, T2;
  int R[3];
  for (int i = 0; i < 3; i++) {
    std::cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    serialize(T1, h1, m1, s1);
    serialize(T2, h2, m2, s2);
    deserialize(R, T2 - T1);
    std::cout << R[0] << " " << R[1] << " " << R[2] << std::endl;
  }
}