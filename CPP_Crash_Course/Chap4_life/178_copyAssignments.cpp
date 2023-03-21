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

  SimpleString(const SimpleString &other)
      : max_size{other.max_size}, buffer{new char[other.max_size]},
        length{other.length} {
    strncpy(buffer, other.buffer, max_size);
  }

  SimpleString &operator=(const SimpleString &other) {
    if (this == &other)
      return *this;
    const auto new_buffer = new char[other.max_size];
    delete[] buffer;
    buffer = new_buffer;
    max_size = other.max_size;
    length = other.length;
    strncpy(new_buffer, other.buffer, max_size);
    return *this;
  }

  ~SimpleString() { delete[] buffer; }

  void print(const char *x) const { printf("%s: %s", x, buffer); }

  bool apend_line(const char *x) {
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
    if (!string.apend_line(x)) {
      throw std::runtime_error("Not enough memory!");
    }
    string.print("Constructed:");
  }
  ~SimpleStringOwner() { string.print("About to destroy:"); }

private:
  SimpleString string;
};

int main() {
  SimpleString a{50};
  a.apend_line("We apologize for the");
  SimpleString b{50};
  b.apend_line("Last message");
  a.print("a");
  b.print("b");
  b = a;
  a.print("a");
  b.print("b");
}
