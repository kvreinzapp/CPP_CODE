#include <cstdio>

int get(int arr[0], size_t Index) { return arr[Index]; }

int main() {
  int fib[]{1, 1, 2, 3};
  printf("%d", get(fib, 3));
}
