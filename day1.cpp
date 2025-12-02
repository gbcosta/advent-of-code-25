#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

void day2() {
  std::ifstream file;
  file.open("./inputs/d1.txt");

  int dialPosition{50};
  int r{0}, n{0};
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      r += line.size() == 4 ? std::stoi(line.substr(1, 1)) : 0;
      int dir = line[0] == 'R' ? 1 : -1;
      n = line.size() == 4 ? std::stoi(line.substr(2)) * dir
                           : std::stoi(line.substr(1)) * dir;

      r += dialPosition != 0 && n + dialPosition <= 0 || n + dialPosition >= 100
               ? 1
               : 0;

      dialPosition += n;
      dialPosition = dialPosition > 99  ? dialPosition % 100
                     : dialPosition < 0 ? dialPosition + 100
                                        : dialPosition;
    }
    file.close();
    std::cout << r << "\n";
  }
}

void day1() {
  std::ifstream file;
  file.open("./inputs/d1.txt");

  int dialPosition{50};
  int r{0}, n{0};

  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      n = line.size() == 4 ? 2 : 1;
      dialPosition += line[0] == 'R' ? std::stoi(line.substr(n))
                                     : -std::stoi(line.substr(n));

      if (dialPosition > 99) {
        dialPosition -= 100;
      } else if (dialPosition < 0) {
        dialPosition += 100;
      }

      if (dialPosition == 0)
        r++;
    }
    file.close();
    std::cout << r << "\n";
  }
}

int main() {
  day1();
  day2();
  return 1;
}
