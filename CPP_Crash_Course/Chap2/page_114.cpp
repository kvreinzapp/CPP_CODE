#include <cstdio>

struct ClockOfTheLongNow {
  ClockOfTheLongNow(int year_in) {
    if (!set_year(year_in)) {
      year = 2019;
    }
  }
  void add_year() { year++; }
  bool set_year(int new_year) {
    if (new_year < 2019)
      return false;
    year = new_year;
    return true;
  }
  int get_year() { return year; }

private:
  int year;
};

int main() {
  ClockOfTheLongNow clock{2000};
  printf("year: %d\n", clock.get_year());
}
