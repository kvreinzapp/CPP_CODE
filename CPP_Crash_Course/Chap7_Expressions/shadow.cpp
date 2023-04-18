#include <cstddef>
#include <cstdio>
#include <new>

struct Bucket {
  const static size_t data_size{4096};
  std::byte data[data_size];
};

struct Heap {
  void *allocate(size_t bytes) {
    if (bytes > Bucket::data_size)
      throw std::bad_alloc();
    for (size_t i{}; i < n_heap_buckets; i++) {
      if (!buckest_status[i]) {
        buckest_status[i] = true;
        return buckets[i].data;
      }
    }
    throw std::bad_alloc();
  }

  void free(void *p) {
    for (size_t i{}; i < n_heap_buckets; i++) {
      if (buckets[i].data == p) {
        buckest_status[i] = false;
        return;
      }
    }
  }

  const static size_t n_heap_buckets{3};
  Bucket buckets[n_heap_buckets]{};
  bool buckest_status[n_heap_buckets]{};
};

Heap heap;

void *operator new(size_t n_bytes) { return heap.allocate(n_bytes); }
void operator delete(void *p) { return heap.free(p); }

int main() {
  printf("Buckets: %p\n", heap.buckets);
  auto breakfast = new unsigned int{0xC0FFEE};
  auto dinner = new unsigned int{0xbeef};
  printf("breakfast: %p %x\n", breakfast, *breakfast);
  printf("dinner: %p %x\n", dinner, *dinner);
  delete breakfast;
  delete dinner;
  try {
    while (true) {
      new char;
      printf("Allocated a new char.\n");
    }
  } catch (std::bad_alloc &) {
    printf("bad_alloc.\n");
  }
}
