#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
  vector<char> directons{'W', 'A', 'S', 'D'};

  vector<vector<int>> distance{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

  vector<int> start = {0, 0};
  string str;
  getline(cin, str);

  stringstream ss(str);
  vector<string> operations;
  string operation;

  while (getline(ss, operation, ';')) {
    operations.push_back(operation);
  }
  for (auto &op : operations) {
    for (int i = 0; i < 4; ++i) {
      if (op[0] == directons[i]) {
        bool flag = true;
        op = op.substr(1, op.size());
        for (auto c : op) {
          if (!isdigit(c)) {
            flag = false;
            break;
          }
        }
        if (flag) {
          int step = stoi(op);
          start[0] += distance[i][0] * step;
          start[1] += distance[i][1] * step;
        }
      }
    }
  }

  cout << start[0] << "," << start[1] << endl;
}
// 64 位输出请用 printf("%lld")