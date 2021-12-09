#include <iostream>
using namespace std;
using ll = long long;

ll a, b;

int main() {
  cin >> a >> b;
  if (a >= b - 1)
    cout << b;
  else
    cout << a + 1;
}