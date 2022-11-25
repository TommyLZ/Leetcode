// 官方方法： 二维矩阵模拟法
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:

    string convert(string s, int numRows) {
        int n = s.size();

        if (numRows == 1 || numRows >= n) {
            return s;
        }

        int t = numRows * 2 - 2;    // Z字形变换周期
        int c = (n + t - 1) / t * (numRows - 1);  // 计算所需要的列数，积累：c++ 类型除法数据，向上取整，(a-1)/b + 1

        vector<string> mat(numRows, string(c, 0)); // 初始值全部为0

        for (int i = 0, x = 0, y = 0; i < n; ++i) { // 矩阵构造完成
            mat[x][y] = s[i];

            if ( i % t < numRows - 1) { // 使用周期进行模拟
                ++ x;   // 向下移动
            }
            else {
                -- x;
                ++ y;  // 向右上移动
            }
        }

        string ans;

        for (auto &row : mat) {    // 生成答案
            for (char ch : row) {
                if (ch) {
                    ans += ch;
                }
            }
        }

        return ans;
    }
};

int main () {
    Solution solution;

    string s = "PAYPALISHIRING";
    int numRows = 3;

    string res = solution.convert(s, numRows);

    cout << "res: " << res << endl;

    return 0;
}

// 时间复杂度： O(numRows*n)
// 空间复杂度： O(numRows*n)