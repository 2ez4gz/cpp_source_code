//
// Created by jojo on 4/10/23.
//
#include <bitset>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

std::vector<std::string> split(std::string str, char delimiter) {
  std::vector<std::string> tokens;
  std::stringstream ss(str);
  std::string token;
  while (std::getline(ss, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}
bool stoip(string &str, vector<int> &ip) {
  vector<string> ip_str = split(str, '.');
  for (int i = 0; i < 4; ++i) {
    if (ip_str[i].empty() || stoi(ip_str[i]) > 255)
      return false;
    ip[i] = stoi(ip_str[i]);
  }
  return true;
}
bool is_mask(vector<int> &mask) {
  unsigned b = 0;
  for (int i = 0; i < 4; ++i)
    b = (b << 8) + mask[i];
  if (!b)
    return false;
  b = ~b + 1;
  if (b == 1)
    return false;
  if ((b & (b - 1)) == 0)
    return true;
  return false;
}

bool is_private(vector<int> &ip) {
  if (ip[0] == 10)
    return true;
  if (ip[0] == 172 && (ip[1] >= 16 && ip[1] <= 31))
    return true;
  if (ip[0] == 192 && ip[1] == 168)
    return true;
  return false;
}
int main() {

  vector<int> res(7);
  string str;
  while (getline(cin, str)) {

    if (str == "")
      break;
    stringstream ss(str);
    string ele;
    vector<string> pair;
    while (getline(ss, ele, '~')) {
      pair.push_back(ele);
    }
    vector<int> ip(4), mask(4);
    if (!stoip(pair[0], ip)) {
      res[5]++;
      continue;
    }
    if (ip[0] == 0 || ip[0] == 127)
      continue;
    if (!stoip(pair[1], mask) || !is_mask(mask))
      res[5]++;
    else {
      if (is_private(ip))
        res[6]++;
      if (ip[0] > 0 && ip[0] < 127)
        res[0]++;
      else if (ip[0] > 127 && ip[0] < 192)
        res[1]++;
      else if (ip[0] > 191 && ip[0] < 224)
        res[2]++;
      else if (ip[0] > 223 && ip[0] < 240)
        res[3]++;
      else if (ip[0] > 239 && ip[0] < 256)
        res[4]++;
    }
  }
  for (auto i : res) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
// 64 位输出请用 printf("%lld")