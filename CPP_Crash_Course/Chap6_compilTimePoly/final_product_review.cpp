#include <cstdio>
#include <stdexcept>
#include <string>

struct SimpleString {
  SimpleString(size_t max_size) : max_size{max_size}, length{} {
    if (max_size == 0) {
      printf("Max_size at least be 1.");
    }
    buffer = new char[max_size];
    buffer[0] = 0; // wrong
  }
  ~SimpleString() { delete[] buffer; }

  SimpleString(const SimpleString &other)
      : max_size{other.max_size}, length{other.length},
        buffer{new char[other.max_size]} {
    strncpy(buffer, other.buffer, max_size);
  }

  SimpleString(SimpleString &&other) noexcept
      : max_size{other.max_size}, buffer{other.buffer}, length{other.length} {
    other.length = 0;
    other.max_size = 0;
    other.buffer = nullptr;
  }

  SimpleString &operator=(const SimpleString &other) {
    if (this == &other)
      return *this;
    const auto new_buffer = new char[other.max_size];
    delete[] buffer;
    buffer = new_buffer;
    length = other.length;
    max_size = other.max_size;
    std::strncpy(new_buffer, other.buffer, max_size);
    return *this;
  }

  SimpleString &operator=(SimpleString &&other) noexcept {
    if (this == &other)
      return *this;
    delete[] buffer;
    buffer = other.buffer;
    max_size = other.max_size;
    length = other.length;
    other.buffer = nullptr;
    other.max_size = 0;
    other.length = 0;
    return *this;
  }

  void print(const char *tag) const { printf("%s: %s", tag, buffer); }

  bool append_line(const char *x) {
    const auto x_len = strlen(x);
    if (x_len + length > max_size)
      return false;
    std::strncpy(length + buffer, x, max_size - length);
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
