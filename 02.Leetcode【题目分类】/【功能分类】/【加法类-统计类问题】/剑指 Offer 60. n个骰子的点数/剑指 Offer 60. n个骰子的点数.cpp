// 动态规划 + 正向递推
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> dp(6, 1.0 / 6.0);    // 初始概率

        for (int i = 2; i <= n; i++) {
            vector<double> tmp(5 * i + 1, 0);   // i个骰子对应的结果数组

            for (int j = 0; j < dp.size(); j++) {   // 利用（i-1）个骰子的概率进行推导
                for (int k = 0; k < 6; k++) {
                    tmp[j + k] += dp[j] / 6.0;  // 贡献度的计算，最后一个骰子对应的概率是六分之一，所以需要除以6
                }
            }

            dp = tmp;
        }
        return dp;
    }
};


int main() {
    Solution solution;

    int n = 2;  // 骰子的个数

    vector<double> res = solution.dicesProbability(n);

    for (int i = 0; i< res.size(); ++i) {
        cout << res[i] << " ";
    }

    return 0;
}

// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
