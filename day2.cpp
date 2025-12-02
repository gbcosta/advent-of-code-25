#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <utility>
#include <vector>

#include <ranges>

using ll = long long;

using namespace std;
void day2() {
  ifstream file;
  string line{};
  vector<pair<ll, ll>> ids{};
  file.open("./inputs/d2.txt");

  auto getId = [](vector<pair<ll, ll>> &ids, string line) {
    regex re("(\\d+)\\-(\\d+)");
    auto begin = sregex_iterator(line.begin(), line.end(), re);
    auto end = sregex_iterator();
    for (sregex_iterator i = begin; i != end; ++i) {
      smatch match = *i;
      ids.push_back({stoll(match.str(1)), stoll(match.str(2))});
    }
  };

  getline(file, line);
  getId(ids, line);

  file.close();
  ll result{0};

  for (pair const id : ids) {
    for (ll i = id.first; i <= id.second; i++) {
      string n = to_string(i);
      if (n.substr(0, n.size() / 2) == n.substr(n.size() / 2)) {
        result += i;
      }
    }
  }

  cout << result << endl;

  result = 0;
  for (pair const id : ids) {
    for (ll i = id.first; i <= id.second; i++) {
      string n = to_string(i);
      for (int j = 0; j < n.size() / 2; j++) {
        string s{};
        for (int k = 0; k < n.size() / (j + 1); k++) {
          s.append(n.substr(0, j + 1));
        }
        if (s == n) {
          result += i;
          break;
        }
      }
    }
  }
  cout << result << endl;
  file.close();
}

int main() {
  day2();
  return 0;
}
