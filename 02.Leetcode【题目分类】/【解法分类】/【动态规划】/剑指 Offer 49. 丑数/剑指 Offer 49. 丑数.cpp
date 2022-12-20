// 动态规划
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);

        dp[1] = 1;


        int p2 = 1, p3 = 1, p5 = 1;
        // p2, 指向1, 2, 3, 4, 5, 6中，还没使用乘2机会的丑数的位置。该指针的前一位已经使用完了乘以2的机会。
        // p3, 指向1, 2, 3, 4, 5, 6中，还没使用乘3机会的丑数的位置。该指针的前一位已经使用完了乘以3的机会。
        // p5, 指向1, 2, 3, 4, 5, 6中，还没使用乘5机会的丑数的位置。该指针的前一位已经使用完了乘以5的机会。

        // 状态转移方程：dp[i] = min(dp[p2]*2, dp[p3]*3, dp[p5]*5)

        for (int i = 2; i <= n; i++) {

            int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;

            dp[i] = min(min(num2, num3), num5); // min只有两个参数，所以采用两次min实现

            // 需要单个每次进行比较：去重
            if (dp[i] == num2) {
                p2++;
            }

            if (dp[i] == num3) {
                p3++;
            }

            if (dp[i] == num5) {
                p5++;
            }
        }

        return dp[n];
    }
};


int main() {
    Solution solution;
    int n = 10;

    int res = solution.nthUglyNumber(n);

    cout << "the result is :" << res << endl;
    return 0;
}

// 时间复杂度：O(n)
// 空间复杂度：O(n)
