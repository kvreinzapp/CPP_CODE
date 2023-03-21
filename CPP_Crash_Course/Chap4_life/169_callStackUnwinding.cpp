#include <cstdio>
#include <cstring>
#include <stdexcept>

struct SimpleString {
  SimpleString(size_t max_size) : max_size{max_size}, length{} {
    if (0 == max_size) {
      throw std::runtime_error("Max size at least be one.");
    }
    buffer = new char[max_size];
    buffer[0] = 0;
  }
  ~SimpleString() { delete[] buffer; }

  void print(const char *tag) const { printf("%s %s", tag, buffer); }

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
      throw std::runtime_error("Not enough memory.");
    }
    string.print("Constructed:");
  }
  ~SimpleStringOwner() { string.print("About to destroy:"); }

private:
  SimpleString string;
};

void fn_c() {
  SimpleStringOwner c{"cccccccccc"};
  printf("Am i exsist?");
}
void fn_b() {
  SimpleStringOwner b{"b"};
  fn_c();
}

int main() {
  try {
    SimpleStringOwner a{"a"};
    fn_b();
    SimpleStringOwner d{"d"};
  } catch (const std::exception &e) {
    printf("Exception: %s\n", e.what());
  }
}
