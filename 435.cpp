//
// Created by jojo on 2/23/23.
//

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int eraseOverlapIntervals(vector<vector<int>> &intervals) {
  sort(intervals.begin(), intervals.end(),
       [](vector<int> &v1, vector<int> &v2) {
         return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];
       });

  vector<vector<int>> noOverlaps;
  for (int i = 0; i < intervals.size(); ++i) {
    if (noOverlaps.size() == 0) {
      noOverlaps.push_back(intervals[i]);
      continue;
    }
    if (intervals[i][0] == noOverlaps.back()[0])
      continue;
    if (intervals[i][0] >= noOverlaps.back()[1])
      noOverlaps.push_back(intervals[i]);
  }

  return intervals.size() - noOverlaps.size();
}
int main() {
  vector<vector<int>> points = {{-52, 31},  {-73, -26}, {82, 97}, {-65, -11},
                                {-62, -49}, {95, 99},   {58, 95}, {-31, 49},
                                {66, 98},   {-63, 2},   {30, 47}, {-40, -26}};
  int res = eraseOverlapIntervals(points);
  cout << res << endl;

  for (auto i : points) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}