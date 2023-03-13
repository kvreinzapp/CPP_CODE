#include <cstdio>

struct College {
  char name[256];
};

void print_name(College *college_ptr) {
  printf("%s College\n", college_ptr->name);
}

int main() {
  College best_colleges[] = {"ketty", "John", "Zad"};
  print_name(best_colleges);     // decay
  print_name(&best_colleges[0]); // must use &
  print_name(&best_colleges[2]); // must use &
}
