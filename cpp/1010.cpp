#include <iostream>

int min(int a, int b)
{
  return a < b ? a : b;
}

int max(int a, int b)
{
  return a > b ? a : b;
}

int nCr(int n, int r)
{
  int mn = min(r, n - r);
  int mx = max(r, n - r);
  int *arr = new int[mn];
  long long result = 1;
  int left = 1;
  for (int i = 0; i < mn; i++)
  {
    arr[i] = mx + i + 1;
  }

  int k;
  for (int i = 2; i <= mn; i++)
  {
    for (k = 0; k < mn; k++)
    {
      if (arr[k] % i == 0)
      {
        arr[k] /= i;
        break;
      }
    }
    if (k == mn)
    {
      left *= i;
    }
  }

  for (int i = 0; i < mn; i++)
  {
    result *= arr[i];
  }
  delete[] arr;
  return result / left;
}

int main()
{
  int T;
  int N, M;
  std::cin >> T;
  for (int i = 0; i < T; i++)
  {
    std::cin >> N >> M;
    std::cout << nCr(M, N) << std::endl;
  }
}