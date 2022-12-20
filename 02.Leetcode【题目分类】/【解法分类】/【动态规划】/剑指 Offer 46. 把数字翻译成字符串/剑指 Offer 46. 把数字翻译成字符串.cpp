// 动态规划
#include <iostream>
using namespace std;

class Solution {
public:
    int translateNum(int num) {

        string src = to_string(num);    // 将输入数组转换成字符串

        // 重点：状态转移方程：dp[i] = dp[i-1] + dp[i-2]（当最后两位合法时）
        // 为了节省空间，用p表示dp[i-2], q表示dp[i-1], r表示 dp[i]
        // 初始化：dp[i-2]=0, dp[i-1]=0, dp[i] = dp[0] = 1;
        int p = 0, q = 0, r = 1;

        for (int i = 0; i < src.size(); ++i) {
            // i++之后需要更新dp[i-2]和dp[i-1]
            p = q;  // dp[i-2] = dp[i-1];
            q = r;  // dp[i-1] = res;

            r = 0;  // dp[i]置为0，重新计算

            r = q; // 将第i位数字单独进行翻译：dp[i] = dp[i-1];

            if (i == 0) {   // 只有一个数字时，不需要考虑两位，跳出循环
                continue;
            }

            // 以下为两位数的判断过程：
            auto pre = src.substr(i - 1, 2);
            if (pre <= "25" && pre >= "10") {  // 考虑两位数合法的状态
                r += p; // dp[i] += dp[i-2], 实际上符合状态转移方程 dp[i] = dp[i-1] + dp[i-2]
            }
        }
        return r;
    }
};


int main() {
    Solution solution;

    int num = 12258;
    int res = solution.translateNum(num);

    cout << res << endl;
    return 0;
}

// 时间复杂度：数字转化成了字符串，时间复杂度是O(logn)，用n表示整数的大小，则整数转换之后，字符串的长度是O(log n) 以10为底
// 空间复杂度：虽然这里用了滚动数组，动态规划部分的空间代价是 O(1)的，但是这里用了一个临时变量把数字转化成了字符串，故渐进空间复杂度是O(logn)。
