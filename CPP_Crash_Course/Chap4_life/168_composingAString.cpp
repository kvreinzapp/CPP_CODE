#include <cstdio>
#include <cstring>
#include <stdexcept>

struct SimpleString {
  SimpleString(size_t max_size) : max_size(max_size), length{} {
    if (0 == max_size) {
      throw std::runtime_error("Max size at least be 1.");
    }
    buffer = new char[max_size];
    buffer[0] = 0;
  }
  ~SimpleString() { delete[] buffer; }

  void print(const char *x) const { printf("%s: %s", x, buffer); }

  bool apend_line(const char *x) {
    const auto x_len = strlen(x);
    if (x_len + length + 2 > max_size)
      return false;
    std::strncpy(buffer + length, x, max_size - length);
    buffer[length++] = '\n';
    buffer[length] = 0;
    return true;
  }

private:
  size_t max_size;
  size_t length;
  char *buffer;
};

struct SimpleStringOwner {
  SimpleStringOwner(const char *x) : string{10} {
    if (!string.apend_line(x)) {
      throw std::runtime_error("Not enough memory!");
    }
    string.print("Constructed: ");
  }
  ~SimpleStringOwner() { string.print("About to destroy: "); }

private:
  SimpleString string;
};

int main() {
  SimpleStringOwner x{"apple"};
  printf("x is alive\n");
}
