#include <cstdio>

template <typename T, typename Fn>
void transform(Fn fn, T *in, T *out, size_t length) {
  for (size_t i{}; i < length; i++) {
    out[i] = fn(in[i]);
  }
}

int main() {
  constexpr size_t len{3};
  int int_base[]{1, 2, 3}, a[len];
  float float_base[]{10.f, 20.f, 30.f}, b[len];
  auto translate = [](auto x) { return x + 10; };
  transform(translate, int_base, a, len);
  transform(translate, float_base, b, len);
  // transform([](int x) { return x + 10; }, int_base, a, len);
  // transform([](float x) { return x + 10; }, float_base, b, len);
  for (size_t i{}; i < len; i++) {
    printf("Element %zd: %d %f\n", i, a[i], b[i]);
  }
}
