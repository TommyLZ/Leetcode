// 分块+预处理

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefixMax(n), suffixMax(n);

        for (int i = 0; i < n; ++i) {

            if (i % k == 0) {   // 递推公式
                prefixMax[i] = nums[i];
            }
            else {
                prefixMax[i] = max(prefixMax[i - 1], nums[i]);
            }
        }

        for (int i = n - 1; i >= 0; --i) {  // 递推公式
            if (i == n - 1 || (i + 1) % k == 0) {
                suffixMax[i] = nums[i];
            }
            else {
                suffixMax[i] = max(suffixMax[i + 1], nums[i]);
            }
        }

        vector<int> ans;
        for (int i = 0; i <= n - k; ++i) {
            ans.push_back(max(suffixMax[i], prefixMax[i + k - 1]));
        }
        return ans;
    }
};

int main() {

    int k = 3;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};

    Solution solution;

    vector<int> res = solution.maxSlidingWindow(nums, k);

    for (int i = 0; i< res.size(); ++i) {
        cout << res[i] << " ";
    }

    return 0;
}

// 时间复杂度：O(n)
// 空间复杂度: O(n)
