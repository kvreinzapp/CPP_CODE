#include <cstdio>

// template <typename T> constexpr T sum(T x) { return x; }

template <typename... Args> constexpr auto sum(Args... args) {
  return (... + args);
}

// int main() { printf("The sum is %d.\n", sum(2, 4, 6, 8, 10, 12)); }
int main() { printf("The sum is %d.\n", sum(2)); }
