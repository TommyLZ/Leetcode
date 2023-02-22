#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        int ans = INT_MAX;
        int start = 0, end = 0;
        int sum = 0;

        while (end < n) {

            sum += nums[end];

            while (sum >= s) {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {10, 5, 2, 6};
    int k = 100, res;

    res = solution.numSubarrayProductLessThanK(nums, k);

    cout << " the result is " << res << endl;

    return 0;
}

// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
