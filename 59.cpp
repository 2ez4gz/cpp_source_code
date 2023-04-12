//
// Created by jojo on 2/17/23.
//
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        vector<vector<int>> direction = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        cout << direction[0][1] << endl;
        int len = n;
        int num = 1;
        while (len > 0) {
            int x = (n - len) / 2, y = (n - len) / 2;
            for (int i = 0; i < 4; ++i) {
                for (int j = 0;j < len - 1; ++j) {
                    res[x][y] = num++;
                    x += direction[i][0];
                    y += direction[i][1];
                }
                if (len == 1) {
                    res[x][y]= num;
                    break;
                }
            }
            len -= 2;
        }
        return res;
    }
};


int main()
{
    cout << "asasasasasasasasasasas" << endl;

    Solution so;
    vector<vector<int>> res = so.generateMatrix(3);

    cout << res[0][0] << endl;

    cout << res[1][1] << endl;
    cout << "asasasasasasasasasasas" << endl;
    return 0;
}