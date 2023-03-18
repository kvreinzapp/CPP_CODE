#include <cstdio>
#include <stdexcept>

struct Apple {
  void Macbook(const char *mac) { printf("Here: %s\n", mac); }
};

int main() {
  int num1;
  int &ref1 = num1;

  int *num2;
  int &ref2 = num2;
}
