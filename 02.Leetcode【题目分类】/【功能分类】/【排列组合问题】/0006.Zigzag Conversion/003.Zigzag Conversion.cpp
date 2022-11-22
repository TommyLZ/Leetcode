#include <iostream>
using namespace std;

class Solution {
public:
    string convert (string s, int numRows) {
        int n = s.length();

        if (numRows == 1 || numRows >= n) {
            return s;
        }

        string ans;

        int t = numRows * 2 - 2;  // 周期
        
        for (int i = 0; i < numRows; ++i) { // 枚举矩阵的行
            for (int j = 0; j + i < n; j += t) { 
                // 增量为周期t,每一行可以理解成由周期进行划分，j是周期累加器，如果当前行i+累加周期，超过了n，则说明当前行遍历完成，需要转移到新行
                ans += s[j + i];    // 当前周期内的第一个字符 
                if (0 < i && i < numRows - 1 && j + t - i < n) { // 除了矩阵第0行和最后一行之外的其他行在当前周期内的第二个字符
                    ans += s[j + (t - i)];    // 当前周期的第二个字符
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

// 时间复杂度：O(n)，s中的每个字符仅被访问一次
// 空间复杂度：O(1)