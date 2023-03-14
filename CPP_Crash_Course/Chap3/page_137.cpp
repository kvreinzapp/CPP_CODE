#include <cstdio>

struct Element {
  Element *next{};
  void insert_after(Element *new_element) {
    new_element->next = next;
    next = new_element;
  }
  char prefix[2];
  short operating_number;
};

int main() {
  Element trooper1, trooper2, trooper3;
  trooper1.prefix[0] = 'U';
  trooper1.prefix[1] = 'S';
  trooper1.operating_number = 408;
  trooper1.insert_after(&trooper2);
  trooper2.prefix[0] = 'U';
  trooper2.prefix[1] = 'K';
  trooper2.operating_number = 872;
  trooper2.insert_after(&trooper3);
  trooper3.prefix[0] = 'C';
  trooper3.prefix[1] = 'N';
  trooper3.operating_number = 502;

  for (Element *cursor = &trooper1; cursor; cursor = cursor->next) {
    printf("stormtrooper %c%c-%d\n", cursor->prefix[0], cursor->prefix[1],
           cursor->operating_number);
  }
}
