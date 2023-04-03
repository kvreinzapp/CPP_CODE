#include <cstddef>
#include <cstdio>

template <typename T> T mean(const T *values, size_t length) {
  T result{};
  for (size_t i{}; i < length; i++) {
    result += values[i];
  }
  return result / length;
}
