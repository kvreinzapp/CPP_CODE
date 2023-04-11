#include <cstdio>

template <typename T> T square(T value) { return value * value; }

int main() {
  int my_int{3};
  auto result = square(my_int);
}
