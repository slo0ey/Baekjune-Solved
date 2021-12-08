#include <iostream>
using namespace std;

int seg_count[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int n;

int main() {
  cin >> n;

  if (n < 8 || n > 26) {
    cout << "Impossible";
    return 0;
  }

  int test, minute, offset;
  for (int hour = 0; hour < 24; hour++) {
    test = n;
    test -= seg_count[hour / 10];
    test -= seg_count[hour % 10];

    if (4 <= test && test <= 13) {
      for (int d1 = 0; d1 < 6; d1++) {
        for (int d2 = 0; d2 < 10; d2++) {
          if (seg_count[d1] + seg_count[d2] == test) {
            minute = d1 * 10 + d2;

            if (hour < 10) cout << 0;
            cout << hour << ":";
            if (minute < 10) cout << 0;
            cout << minute;
            return 0;
          }
        }
      }
    }
  }
}