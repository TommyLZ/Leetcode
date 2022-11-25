// 标记位模拟法：非官方方法
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:

    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        vector<string> res(numRows);   // 使用一维数组保存每行结果

        int i = 0;  // 行数标志
        int flag = -1;  // 往上走还是往下走的标志
        
        for (char &ch : s) {  // 遍历s
            res[i] += ch;

            if (i == 0 || i == numRows - 1) {  // 当规定行数完成一轮时，需要转换方向
                flag = -flag;
            }

            i += flag;
        }

        for (int i = 1; i < numRows; i++) { // 将每行接起来就是结果
            res[0] += res[i];
        }

        return res[0];
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

// 时间复杂度： O(n)
// 空间复杂度： O(n)