#include <cstddef>
#include <cstdio>

struct TestEqual {
  TestEqual(char x) : x{x} {}
  size_t index{}, result{};
  bool operator()(const char *str) const {
    while (str[index] == x)
      return true;
    return false;
  }

private:
  const char x;
};

int main() {
  auto Sally = TestEqual{'n'}("sally");
  printf("%d\n", Sally);
  TestEqual Tom{'t'};
  auto tom = Tom("tom");
  printf("%d\n", tom);
}
