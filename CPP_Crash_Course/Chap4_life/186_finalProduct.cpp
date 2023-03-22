#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <utility>

struct SimpleString {
  SimpleString(size_t max_size) : max_size(max_size), length{} {
    if (0 == max_size) {
      throw std::runtime_error("Max size at least be 1");
    }
    buffer = new char[max_size];
    buffer[0] = 0;
  }

  ~SimpleString() { delete[] buffer; }

  // copy constructor
  SimpleString(const SimpleString &other)
      : max_size{other.max_size}, buffer{new char[other.max_size]},
        length{other.length} {
    strncpy(buffer, other.buffer, max_size);
  }

  // move constructor
  SimpleString(SimpleString &&other) noexcept
      : max_size{other.max_size}, length{other.length}, buffer{other.buffer} {
    other.max_size = 0;
    other.length = 0;
    other.buffer = nullptr;
  }

  // copy assignment
  SimpleString &operator=(const SimpleString &other) {
    if (this == &other)
      return *this;
    const auto new_buffer = new char[other.max_size];
    delete[] buffer;
    buffer = new_buffer;
    length = other.length;
    max_size = other.max_size;
    strncpy(new_buffer, other.buffer, max_size);
    return *this;
  }

  // move assignment
  SimpleString &operator=(SimpleString &&other) noexcept {
    if (this == &other)
      return *this;
    delete[] buffer;
    buffer = other.buffer;
    max_size = other.max_size;
    length = other.length;
    other.buffer = nullptr;
    other.length = 0;
    other.max_size = 0;
    return *this;
  }

  void print(const char *tag) const { printf("%s: %s", tag, buffer); }
  bool append_line(const char *x) {
    auto x_len = strlen(x);
    if (x_len + length + 2 > max_size)
      return false;
    strncpy(buffer + length, x, max_size - length);
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
  SimpleStringOwner(SimpleString &&x) : string{std::move(x)} {
    string.print("hello");
  }

private:
  SimpleString string;
};

int main() {
  SimpleString x{30};
  x.append_line("I'm original");
  x.print("a");
  SimpleStringOwner y{std::move(x)};
}
