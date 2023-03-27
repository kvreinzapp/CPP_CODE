#include <cstdio>

struct Logger {
  virtual ~Logger() = default;
  virtual void log_transfer(long from, long to, double amount) = 0;
};

struct ConsoleLogger : Logger {
  void log_transfer(long from, long to, double amount) override {
    printf("[con] %ld %ld %f\n", from, to, amount);
  }
};

struct FileLogger : Logger {
  void log_transfer(long from, long to, double amount) override {
    printf("[file] %ld %ld %f\n", from, to, amount);
  }
};

// struct Bank {
//   Bank(Logger &logger) : logger{logger} {}
//   void make_transfer(long from, long to, double amount) {
//     logger.log_transfer(from, to, amount);
//   }
//
// private:
//   Logger &logger;
// };
//
// int main() {
//   ConsoleLogger logger;
//   Bank bank{logger};
//   bank.make_transfer(23, 58, 43.43);
// }

struct Bank {
  void set_logger(Logger *new_logger) { logger = new_logger; }
  void make_transfer(long from, long to, double amount) {
    logger->log_transfer(from, to, amount);
  }

private:
  Logger *logger;
};

int main() {
  ConsoleLogger console_logger;
  FileLogger file_logger;
  Bank bank;
  bank.set_logger(&console_logger);
  bank.make_transfer(200, 399, 43.3);
  bank.set_logger(&file_logger);
  bank.make_transfer(323, 43499, 433.3);
}
