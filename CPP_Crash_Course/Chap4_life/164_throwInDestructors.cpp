#include <cstdio>
#include <stdexcept>

struct Apple {
  Apple() { printf("Buy one!\n"); }
  ~Apple() { throw std::runtime_error("You got me."); }
};

int main() {
  try {
    Apple mac;
    throw std::runtime_error("I'm throwed in main");
  } catch (const std::exception &e) {
    printf("Caught exception: %s\n)", e.what());
  }
}
