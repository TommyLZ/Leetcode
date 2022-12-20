// 动态规划： 简单

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for (int j = 1; j < n; ++j) { // 初始化第一行
            grid[0][j] += grid[0][j-1];
        }

        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i-1][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += max(grid[i-1][j], grid[i][j-1]);
            }
        }

        return grid[m-1][n-1];
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int res = solution.maxValue(grid);

    cout << "the result is :" << res << endl;
    return 0;
}

// 时间复杂度：O(m*n)
// 空间复杂度：O(1)
