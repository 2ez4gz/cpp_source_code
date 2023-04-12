//
// Created by jojo on 2/23/23.
//

#include <bitset>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<bitset<9>> rows;
vector<bitset<9>> cols;
vector<vector<bitset<9>>> ceils;
int cnt;
bitset<9> findRestNum(int i, int j) {
  return ~(rows[i] | cols[j] | ceils[i / 3][j / 3]);
}

void fillij(int i, int j, int n, bool val) {
  rows[i].set(n, val);
  cols[j].set(n, val);
  ceils[i / 3][j / 3].set(n, val);
}

bool dfs(vector<vector<char>> &board) {
  if (cnt == 0) {
    return true;
  }

  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (board[i][j] != '.')
        continue;

      auto Restij = findRestNum(i, j);
      if (Restij.count() == 0) {
        return false;
      }
      for (int k = 0; k < 9; ++k) {
        if (!Restij.test(k))
          continue;

        fillij(i, j, k, 1);
        cnt--;

        board[i][j] = static_cast<char>(k + '1');
        if (dfs(board))
          return true;
        cnt++;
        fillij(i, j, k, 0);
        board[i][j] = '.';
      }
      return false;
    }
  }
  return false;
}

void solveSudoku(vector<vector<char>> &board) {

  rows = vector<bitset<9>>(9, bitset<9>());
  cols = vector<bitset<9>>(9, bitset<9>());
  ceils = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[i].size(); ++j) {
      if (board[i][j] == '.') {
        cnt++;
        continue;
      }

      int n = board[i][j] - '1';
      fillij(i, j, n, 1);
    }
  }

  dfs(board);
  return;
}
int main() {
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  solveSudoku(board);
  for (auto row : board) {
    for (auto c : row) {
      cout << c << " ";
    }
    cout << endl;
  }
}