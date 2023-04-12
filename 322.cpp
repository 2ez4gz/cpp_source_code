//
// Created by jojo on 2/23/23.
//

#include <iostream>
#include <map>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;
int tickets_num;
unordered_map<string, map<string, int>> um;
vector<string> res;
bool find_path() {
  if (res.size() == tickets_num + 1)
    return true;

  for (auto &pair : um[res.back()]) {
    if (pair.second > 0) {
      res.push_back(pair.first);
      pair.second--;
      if (find_path())
        return true;
      pair.second++;
      res.pop_back();
    }
  }
  return false;
}

vector<string> findItinerary(vector<vector<string>> &tickets) {
  res.push_back("JFK");
  tickets_num = tickets.size();

  for (auto ticket : tickets) {
    um[ticket[0]][ticket[1]]++;
  }
  find_path();
  return res;
}

int main() {
  vector<vector<string>> tickets{{"JFK", "SFO"},
                                 {"JFK", "ATL"},
                                 {"SFO", "ATL"},
                                 {"ATL", "JFK"},
                                 {"ATL", "SFO"}};

  auto res = findItinerary(tickets);

  for (auto r : res) {
    cout << r << " ";
  }
}