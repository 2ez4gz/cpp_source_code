//
// Created by jojo on 2/23/23.
//

#include <iostream>
#include <vector>
#include <stack>


using namespace std;

vector<vector<int>> res;
vector<int> path;

void traver(int k, int n, int sum, int start) {
    if (k < 0) return;
    if (sum > n) return;
    if (n == sum && k == 0) {
        for(int i: path) {
            cout << i << " ";
        }
        res.push_back(path);
        return;
    }
    for (int i = start; i <= 9 - k + 1; ++i) {
        path.push_back(i);
        traver(k - 1, n, sum + i, i + 1);
        path.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    traver(k, n, 0, 1);
    return res;
}

int main()
{
    combinationSum3(9, 45);
}