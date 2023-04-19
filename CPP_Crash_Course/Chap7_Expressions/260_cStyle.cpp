#include <cstdio>
void trainwreck(const char *read_only) {
  auto as_unsigned = const_cast<char *>(read_only);
  *as_unsigned = 'f'; // Crashes on Windows 10 x64
}

void carbon_thaw(const int &encased_solo) {
  // encased_solo++;// Compiler error; modifying const
  auto &hibernation_sick_solo = const_cast<int &>(encased_solo);
  hibernation_sick_solo++;
}

int main() {
  auto *ezra = "hello";
  printf("before trainwreck: %s\n", ezra);
  trainwreck(ezra);
  printf("after trainwreck: %s\n", ezra);
  // auto duck{3};
  // printf("Duck1: %d\n", duck);
  // carbon_thaw(duck);
  // printf("Duck2: %d\n", duck);
}
