//
// Created by jojo on 4/11/23.
//
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;

int main() {
  map<int, vector<pair<int, string>>> mp;
  int n;
  cin >> n;
  vector<string> vecs;
  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;
    vecs.push_back(str);
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int num;
    cin >> num;
    if (mp.find(num) == mp.end()) {
      mp[num] = vector<pair<int, string>>();
    }
  }
  for (int i = 0; i < n; ++i) {
    for (auto &num_vec : mp) {
      if (vecs[i].find(to_string(num_vec.first)) != string::npos) {
        num_vec.second.emplace_back(i, vecs[i]);
      }
    }
  }
  vector<string> res(1);
  int count = 0;
  for (auto &ele : mp) {
    if (ele.second.empty())
      continue;
    res.push_back(to_string(ele.first));
    count++;
    res.push_back(to_string(ele.second.size()));
    count++;
    for (auto &num : ele.second) {
      res.push_back(to_string(num.first));
      count++;
      res.push_back(num.second);
      count++;
    }
  }
  res[0] = to_string(count);
  for (auto &str : res) {
    cout << str << " ";
  }
}
// 64 位输出请用 printf("%lld")