#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < 32; ++i) { // 最多需要考虑32位
            int total = 0;

            for (int num: nums) { // 遍历
                total += ((num >> i) & 1);
            }

            if (total % 3) {
                ans |= (1 << i); // 按位或；保留所有的1
            }
        }
        return ans;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {2, 2, 3, 2};

    int res = solution.singleNumber(nums);

    cout << res << endl;

    return 0;
}
