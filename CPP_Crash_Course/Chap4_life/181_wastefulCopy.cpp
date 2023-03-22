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

  void print(const char *x) const { printf("%s %s", x, buffer); }

  bool append_line(const char *x) {
    const auto x_len = strlen(x);
    if (x_len + length + 2 > max_size)
      return false;
    std::strncpy(buffer + length, x, max_size - length);
    length += x_len;
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
    if (!string.append_line(x)) {
      throw std::runtime_error("Not enough memory!");
    }
    string.print("Constructed:");
  }

  SimpleStringOwner(const SimpleString &my_string) : string{my_string} {}

  ~SimpleStringOwner() { string.print("About to destroy:"); }

private:
  SimpleString string;
};

int main() {
  SimpleString a{50};
  a.append_line("we apologize for the");
  a.append_line("inconvenience.");
  SimpleStringOwner b{a};
}
