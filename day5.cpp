#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using ll = long long;
using namespace std;

int part1(vector<ll> &ids, vector<pair<ll, ll>> &_ranges) {
  int result{};

  for (const ll &id : ids) {
    for (const pair<ll, ll> &range : _ranges) {
      if (id >= range.first && id <= range.second) {
        result++;
        break;
      }
    }
  }

  return result;
}

ll part2(vector<ll> &ids, vector<pair<ll, ll>> _ranges) {

  ll result{};

  sort(_ranges.begin(), _ranges.end());

  for (int i = 0; i < _ranges.size(); i++) {
    for (int j = i + 1; j < _ranges.size(); j++) {
      if (_ranges[i].second == 0) {
        break;
      }
      if (_ranges[i].second >= _ranges[j].second) {
        _ranges[j] = {0, 0};
      } else if (_ranges[i].second >= _ranges[j].first) {
        result += _ranges[j].first - _ranges[i].first;
        break;
      } else if (_ranges[i].second < _ranges[j].first) {
        result += _ranges[i].second - _ranges[i].first + 1;
        break;
      }
    }
    if (i == _ranges.size() - 1 && _ranges[i].first != 0) {
      result += _ranges[i].second - _ranges[i].first + 1;
    }
  }
  return result;
}

int main() {
  std::ifstream file;
  file.open("./inputs/d5.txt");
  string input{};
  vector<pair<ll, ll>> _ranges{};
  vector<ll> ids{};
  bool blank = false;

  while (getline(file, input)) {
    if (input == "")
      blank = true;
    if (!blank) {
      int a = input.find('-');
      _ranges.emplace_back(pair{stoll(input.substr(0, a)),
                                stoll(input.substr(a + 1, input.size() - a))});
    } else if (blank && input != "") {
      ids.emplace_back(stoll(input));
    }
  }

  cout << part1(ids, _ranges) << '\n';
  cout << part2(ids, _ranges) << '\n';

  return 0;
}
