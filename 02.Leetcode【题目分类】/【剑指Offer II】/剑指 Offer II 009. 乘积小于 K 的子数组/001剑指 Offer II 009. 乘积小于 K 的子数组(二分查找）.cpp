#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), ret = 0;

        int prod = 1, i = 0;

        for (int j = 0; j < n; j++) { // 先确定j

            prod *= nums[j];

            while (i <= j && prod >= k) {

                prod /= nums[i];  // 采用边乘边除边判断
                i++;
            }

            ret += j - i + 1;
        }
        return ret;
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

// 时间复杂度：O(n)
// 空间复杂度：O(1)
