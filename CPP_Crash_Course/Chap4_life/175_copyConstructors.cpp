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
  a.apend_line("We appologize for the");
  SimpleString a_copy{a};
  a.apend_line("inconvenience.");
  a_copy.apend_line("incontinence.");
  a.print("a");
  a_copy.print("a_copy");
}
