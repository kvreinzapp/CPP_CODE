#include <stdexcept>

template <typename T>
  requires std::is_copy_constructible<T>::value
T get_copy(T *pointer) {
  if (!pointer)
    throw std::runtime_error("Null-pointer dereference");
  return *pointer;
}

struct Highlander {
  Highlander() = default;
  Highlander(const Highlander &) = delete;
};

int main() {
  Highlander conner;
  auto conner_ptr = &conner;
  auto conner_copy = get_copy(conner_ptr);
}
