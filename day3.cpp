#include <fstream>
#include <iostream>
#include <string>

void part1() {
  std::ifstream file;
  file.open("./inputs/d3.txt");
  std::string input_line{};
  int largest{-1};
  int second{-1};
  int result{0};
  int largest_position{};
  std::string joltage = "11";

  while (getline(file, input_line)) {
    for (int i = 0; i < input_line.size() - 1; i++) {
      if (largest < input_line[i] - '0') {
        largest = input_line[i] - '0';
        joltage[0] = input_line[i];
        largest_position = i + 1;
      }
    }

    for (int i = largest_position; i < input_line.size(); i++) {
      if (second < input_line[i] - '0') {
        second = input_line[i] - '0';
        joltage[1] = input_line[i];
      }
    }
    result += std::stoi(joltage);
    largest = -1;
    second = -1;
    largest_position = {};
  }
  std::cout << result << '\n';
}
using ll = long long;

void part2() {
  std::ifstream file;
  file.open("./inputs/d3.txt");
  std::string input_line{};

  ll largest{-1};
  ll result{0};
  int largest_position{};
  std::string joltage = "";
  while (getline(file, input_line)) {
    while (joltage.size() < 12) {
      for (int i = largest_position;
           i < input_line.size() - 11 + joltage.size(); i++) {
        if (largest < input_line[i]) {
          largest = input_line[i];
          largest_position = i + 1;
        }
      }
      joltage.push_back(largest);
      largest = -1;
    }
    result += std::stoll(joltage);
    largest_position = {};
    largest = -1;
  }
  std::cout << result << '\n';
}

int main() {
  part2();
  part1();
}
