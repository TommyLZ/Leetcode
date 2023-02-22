#include <iostream>
#include <climits>
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
        // sums[0] = 0 意味着前 0 个元素的前缀和为 0
        // sums[1] = A[0] 前 1 个元素的前缀和为 A[0]
        // 以此类推

        for (int i = 1; i <= n; i++) {  // 计算前缀和
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        for (int i = 1; i <= n; i++) {  // 确定每个子数组的开始下标
            int target = s + sums[i - 1];   // (也就是说，假设从数组中下标为i的符号开始累加，累加到s), 而这个过程，相当于从第一个数字开始累加，加到下标为i之前的数字sum[i-1]，再加上s
            // 这两个过程的终点的索引都是一样的，所以对每个不同的开始下标i，都有一个相同的前缀和数组，能够查到从i开始累加到target的时候，对应的最后一个元素的索引j

            auto bound = lower_bound(sums.begin(), sums.end(), target); // 在sums中利用二分查找法寻找target，或者这里可以直接用二分查找的代码替代
            // 对于每个开始下标i，可通过二分查找得到大于或等于i的最小下标bound(因为是从i开始累加的，所以肯定是大于等于i的)

            if (bound != sums.end()) { // 找到了对应的索引
                ans = min(ans, static_cast<int>((bound - sums.begin()) - (i - 1))); // 子数组的长度是bound - i - 1, 可能内置函数需要强制类型转换， 不断比较，取最小值即可
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

int main(){
    Solution solution;
    int target = 7;
    vector<int> nums {2,3,1,2,4,3};
    int ans;

    ans = solution.minSubArrayLen(target, nums);

    cout << "ans: " << ans << endl;

    return 0;
}
