#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int> &nums) {

        // 第三个形参是累加的初值
        int total = accumulate(nums.begin(), nums.end(), 0);

        int sum = 0;

        for (int i = 0; i < nums.size(); ++i) {


            if (2 * sum + nums[i] == total) {
                return i;
            }

            sum += nums[i]; // 从左侧开始累加
        }

        return -1;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {1,7,3,6,5,6};

    int res = solution.pivotIndex(nums);

    cout << "the result is " << res << endl;

    return 0;
}

// 时间复杂度: O(n)
// 空间复杂度: O(1)
