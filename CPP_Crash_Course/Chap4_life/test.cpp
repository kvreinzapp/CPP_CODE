#include <cstdio>
#include <cstring>
#include <stdexcept>

struct SimpleOne {
  SimpleOne(size_t max_size) : max_size{}, length{} {
    if (max_size == 0)
      throw std::runtime_error(" at least be 1");
    printf("max:%td", max_size);
    printf("length:%td", length);
  }

private:
  size_t length;
  size_t max_size;
};

int main() { SimpleOne x{20}; }
