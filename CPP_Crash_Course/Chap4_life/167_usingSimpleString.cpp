#include <cstdio>
#include <cstring>
#include <stdexcept>

struct SimpleString {
  SimpleString(size_t max_size) : max_size{max_size}, length{} {
    if (0 == max_size) {
      throw std::runtime_error("Max size at least be 1.\n");
    }
    buffer = new char[max_size];
    buffer[0] = 0;
  }
  ~SimpleString() { delete[] buffer; }
  void print(const char *tag) const { printf("%s: %s", tag, buffer); }

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

int main() {
  SimpleString string{115};
  string.append_line("I have never been hurt by what?");
  string.append_line("by anything I didn't say.");
  string.print("citeA");
}
