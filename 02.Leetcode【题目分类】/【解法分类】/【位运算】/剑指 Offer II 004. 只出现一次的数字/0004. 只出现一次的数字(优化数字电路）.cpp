#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;

        // 先计算b，再用新的b计算a（进行了表达式的优化）
        for (int num: nums) {
            b = ~a & (b ^ num);
            a = ~b & (a ^ num);
        }

        return b;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 2, 3, 2};

    int res = solution.singleNumber(nums);

    cout << res << endl;

    return 0;
}

// 时间复杂度：O(n)
// 空间复杂度：O(1)
