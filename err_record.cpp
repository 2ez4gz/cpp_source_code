//
// Created by jojo on 4/10/23.
//
#include <algorithm>
#include <deque>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string> split(string &str, char signal) {
  stringstream ss(str);
  vector<string> res;
  string token;
  while (getline(ss, token, signal))
    res.push_back(token);
  return res;
}
int main() {
  string str;
  deque<string> res;
  unordered_map<string, int> um;
  int index = 0;
  while (getline(cin, str)) {
    if (str == "")
      break;
    auto pos_line = split(str, ' ');
    auto pos_vec = split(pos_line[0], '\\');
    auto position = pos_vec.back();
    if (position.size() > 16)
      position = position.substr(position.size() - 16);
    position += " ";
    position += pos_line[1];
    if (um.find(position) == um.end()) {
      um[position] = 1;
      res.push_back(position);
      ;
      if (res.size() > 8)
        res.pop_front();
    } else {
      um[position]++;
    }
  }
  for (auto &record : res) {
    if (record == "")
      continue;
    cout << record << " " << um[record] << endl;
  }

  return 0;
}