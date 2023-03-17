#include <cstdio>
#include <stdexcept>

struct Apple {
  void eat(int num) {
    if (2 == num) {
      throw std::runtime_error("You find the message");
    }
    printf("step%d\n", num);
  }
};

int main() {
  Apple apple;
  try {
    apple.eat(1);
    apple.eat(2);
    apple.eat(3);
  } catch (std::runtime_error &e) {
    printf("Error: %s", e.what());
  }
}
