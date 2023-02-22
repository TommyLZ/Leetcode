#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        int ans = INT_MAX;

        vector<int> sums(n + 1, 0);
        // 为了方便计算，令 size = n + 1
        // sums[0] = 0 意味着前 0 个元素的前缀和为 0 （默认存储的就是0）
        // sums[1] = A[0] 前 1 个元素的前缀和为 A[0]
        // 以此类推

        for (int i = 1; i <= n; i++) { // 建立sum数组
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        for (int i = 1; i <= n; i++) {

            // 这一部分看题解的说明
            int target = sums[i - 1] + s; // 计算target, 理论上target - sum[i-1] >= s

            // 在 sum 中找到不小于target的第一个元素
            auto bound = lower_bound(sums.begin(), sums.end(), target);

            // 输出bound观察具体值的方法
            // vector<int>::iterator iter = bound; （所以实际上是个指针）
            // cout << "bound = " << *iter << endl;

            // vector.end是指向最后一个元素的下一个位置，表示bound不存在

            // 如果确实存在该元素：
            if (bound != sums.end()) {

            // static_cast；强制类型转换，需要将指针的差转换成整型

                // 为什么要减 i-1 ？ 题目要求是长度
                // 为什么是最小值？ 题目要求是最小连续
                ans = min(ans, static_cast<int>((bound - sums.begin()) - (i - 1)));
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};


int main() {

    Solution solution;
    vector<int> nums = {2,3,1,2,4,3};
    int s = 7;

    int res = solution.minSubArrayLen(s, nums);

    cout << " the result is " << res << endl;
    return 0;
}

// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
