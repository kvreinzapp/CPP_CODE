#include <cstdio>

enum class Items { Add, Subtract, Multiply, Divide };

int main() {
  Items item = Items::Divide;

  switch (item) {
  case Items::Divide: {
    printf("Divide");
  } break;
  case Items::Add: {
    printf("Add");
  } break;
  default: {
    printf("Error");
  }
  }
}
