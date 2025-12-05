#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int delete_rolls(const int &height, const int &width, std::vector<char> &grid,
                 const bool change_grid = false) {
  int result{0};
  int sum{};
  int last_sum{};

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      for (int k = -1; k < 2; k++) {
        if (grid[y * width + x] == '.')
          break;
        if (y - 1 >= 0) {
          if (x + k >= 0 && x + k < width &&
              grid[((y - 1) * width) + x + k] == '@') {
            result++;
          }
        }
        if (y + 1 < height) {
          if (x + k >= 0 && x + k < width &&
              grid[((y + 1) * width) + x + k] == '@') {
            result++;
          }
        }
        if (x + k >= 0 && x + k < width && k != 0 &&
            grid[(y * width) + x + k] == '@') {
          result++;
        }
      }
      if (result < 4 && grid[y * width + x] != '.') {
        sum++;
        if (change_grid)
          grid[y * width + x] = '.';
      }
      result = 0;
    }
  }
  return sum;
}

int day4() {
  std::ifstream file;
  std::string input{};
  std::vector<char> grid;
  int height{};
  int width{};

  file.open("./inputs/d4.txt");
  while (std::getline(file, input)) {
    width = input.size();
    for (const char _char : input) {
      grid.emplace_back(_char);
    }
    height++;
  }
  file.close();

  std::cout << delete_rolls(height, width, grid, false) << '\n';

  int sum{};
  int last_sum{0};

  do {
    last_sum = sum;
    sum += delete_rolls(height, width, grid, true);
  } while (sum != last_sum);

  std::cout << sum << '\n';

  return 0;
}

int main() { day4(); }
