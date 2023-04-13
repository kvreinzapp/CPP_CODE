#include <cstddef>
#include <cstdio>
#include <type_traits>

template <typename T>
concept bool Averagable() {
  return std::is_default_constructible<T>::value && requires(T a, T b) {
    { a += b } -> T;
    {
      a / size_t { 1 }
    } -> T;
  };
}

template <Averagable T> const T mean(const T *values, size_t length) {
  T result{};
  for (size_t i{}; i < length; i++) {
    result += values[i];
  }
  return result / length;
}

int main() {
  // const double nums_d[]{1.0f, 2.0f, 3.0f, 4.0f};
  // const auto result1 = mean(nums_d, 4);
  // printf("double: %f\n", result1);
  //
  // const float nums_f[]{1.0, 2.0, 3.0, 4.0};
  // const auto result2 = mean(nums_f, 4);
  // printf("float: %f\n", result2);
  //
  // const size_t nums_c[]{1, 2, 3, 4};
  // const auto result3 = mean(nums_c, 4);
  // printf("size_t: %d\n", result3);

  auto value1 = 0.0;
  auto value2 = 1.0;
  const double *values[] = {&value1, &value2};
  mean(values, 2);
}
