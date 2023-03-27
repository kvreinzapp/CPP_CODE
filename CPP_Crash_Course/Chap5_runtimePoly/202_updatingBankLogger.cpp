#include <cstdio>
#include <stdexcept>

struct logger {
  virtual ~logger() = default;
  virtual void log_transfer(long from, long to, double account) = 0;
};

struct ConsoleLogger : logger {
  void log_transfer(long from, long to, double account) override {
    printf("[cons] %ld -> %ld: %f\n", from, to, account);
  }
};

struct FileLogger : logger {
  void log_transfer(long from, long to, double account) override {
    printf("[file] %ld,%ld,%f\n", from, to, account);
  }
};

// enum class LoggerType { Console, File };
//
// struct Bank {
//   Bank() : type{LoggerType::Console} {}
//
//   void set_logger(LoggerType new_type) { type = new_type; }
//
//   void make_transfer(long from, long to, double account) {
//     switch (type) {
//     case LoggerType::Console: {
//       consoleLogger.log_transfer(from, to, account);
//       break;
//     }
//     case LoggerType::File: {
//       fileLogger.log_transfer(from, to, account);
//       break;
//     }
//     default: {
//       throw std::logic_error("Unknown logger Type encountered.");
//     }
//     }
//   }
//
// private:
//   LoggerType type;
//   ConsoleLogger consoleLogger;
//   FileLogger fileLogger;
// };
//
// int main() {
//   Bank bank;
//   bank.make_transfer(1000, 2000, 49.95);
//   bank.make_transfer(2000, 4000, 20.00);
//   bank.set_logger(LoggerType::File);
//   bank.make_transfer(3000, 2000, 75.00);
// }
