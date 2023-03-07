#include <cstdio>

struct clock {
  void year_add() { year++; }
  int year;
};

int main() {
  clock cl;
  cl.year = 2018;
  cl.year_add();
  printf("Year: %d\n", cl.year);
  cl.year_add();
  printf("Year: %d\n", cl.year);
}
