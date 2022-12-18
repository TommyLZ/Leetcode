// 动态规划问题
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1);    // 默认初始化为0

        for (int i=2; i<=n; ++i) {
            int curMax = 0;
            for (int j=1; j<i; ++j) {
                curMax = max(curMax, max(j * (i-j), j * dp[i-j]));
            }
            dp[i] = curMax;
        }

        return dp[n];
    }
};

int main()
{
    Solution solution;
    int n = 10;
    int res = solution.cuttingRope(n);

    cout << "the result is: " << res << endl;
    return 0;
}
