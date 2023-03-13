#include <cstdio>

struct Apple {
  char name[255];
};

void pint_name(Apple *apples, size_t number) {
  for (size_t i = 0; i < number; i++) {
    printf("%s product\n", apples[i].name);
  }
}

int main() {
  Apple apple[] = {"mac", "iphone", "ipad"};
  pint_name(apple, sizeof(apple) / sizeof(Apple));
}
