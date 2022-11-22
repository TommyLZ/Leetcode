// 动态规划方案
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    string LongestPalindrome(string s) {
        int n = s.size();   // 字符串长度
        if (n < 2) {
            return s;
        }

        int maxLen = 1;
        int begin = 0;

        // dp[i][j]表示s[i...j]是否是回文子串
        vector<vector<int>> dp(n, vector<int>(n)); // 创建二维数组 n*n

        // 初始化：所有长度为1的子串都是回文串
        for (int i=0; i<n; i++) {
            dp[i][i] = true;
        }

        // 递推开始
        // 先枚举子串长度
        for (int L = 2; L <= n; L++) {
            // 枚举左边界， 左边界上限设置宽松
            for (int i = 0; i < n; i++) {
                // 根据子串长度L计算出右边界
                int j = L + i - 1;
                // 如果右边界越界，可以退出当前循环
                if (j >= n) {
                    break;
                }
                
                if (s[i] != s[j]) { // 判断是否符合回文子串
                    dp[i][j] = false;   // 最左和最右边的字母不同
                }
                else {
                    if (j - i < 3) { // 最左和最右边的字母相同，且子串长度小于等于3
                        dp[i][j] = true;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1]; // 继续缩小子串范围, 看内部是否依然是回文子串
                    }
                }

                // 只要 dp[i][L] = true成立，就表示子串s[i...L]是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }

        return s.substr(begin, maxLen); // 返回子串
    }

};


int main () {
    Solution solution;

    // string s = "babad";
    string s = "cbbd";

    string res = solution.LongestPalindrome(s);

    cout << "result: " << res << endl;
    return 0;
}