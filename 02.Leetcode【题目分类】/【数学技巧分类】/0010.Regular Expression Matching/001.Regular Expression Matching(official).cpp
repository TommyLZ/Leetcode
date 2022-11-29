// 动态规划(官方版)
// 难度较大，看视频解析，清晰易懂
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&] (int i, int j) { // [&]为捕获列表，表示按照引用捕获外部变量p和s. 参数列表为(int i, int j)
            if (i == 0) {   // s[i-1]越界，匹配失败
                return false;
            }

            if (p[j-1] == '.') {
                return true;
            }

            return s[i-1] == p[j-1]; // s和p的下标是从0开始，所以f比它们的下标要多1才能一致
        };  // c++ lambda表达式

        vector<vector<int>> f(m+1, vector<int>(n+1)); // 定义二维数组f, m+1行，n+1列
        // 没有指定初始化的情况下，默认值为0

        f[0][0] = true; // 空格和空格是匹配的，初始值设置

        for (int i=0; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {  // j选择从1开始
                if (p[j-1] == '*') {
                    f[i][j] |= f[i][j-2];   // 按位或后赋值： result = result | expression
                    // 碰到* 回退两位进行查看，即f[i-1][j-3]: 如果是true，则直接就是true
                    // 如果不是true，则查看s[i-1]和p[j-2], 如下程序语句
                    if (matches(i, j-1)) {  // 辅助函数，匹配s[i-1]和p[j-2]
                    // 如果匹配， 进一步看s[i-2]和p[j-1], 如果为true，则f[i][j]为true，否则，说明签名的部分和*不匹配，结果为false
                        f[i][j] |= f[i-1][j]; 
                    }
                } 
                else {
                    if (matches(i, j)) {    // 辅助函数 匹配s[i-1]和p[j-1]
                        f[i][j] |= f[i-1][j-1];
                    }   // 函数默认值是0，所以不匹配的时候不用进行赋值
                }
            }
        }

        return f[m][n];
    }
};

int main () {
    Solution solution;
    string s = "ab";
    string p = ".*";

    bool res = solution.isMatch(s, p);

    cout << "the result is:" << res << endl;
    return 0;
}