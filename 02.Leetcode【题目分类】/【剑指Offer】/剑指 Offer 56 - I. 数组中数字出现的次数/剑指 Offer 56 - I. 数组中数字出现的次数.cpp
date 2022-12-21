#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ret = 0;

        for (int n : nums)
            ret ^= n;   // 所有元素的异或和

        int div = 1;

        while ((div & ret) == 0)    // 找到最低位的1
            div <<= 1;

        int a = 0, b = 0;

        for (int n : nums)  // 按照最低位的1的位置进行分组
            if (div & n)
                a ^= n;
            else
                b ^= n;

        return vector<int>{a, b};
    }
};


int main() {
    Solution solution;
    vector<int> nums = {1, 2, 10, 4, 1, 4, 3, 3};

    vector<int> res = solution.singleNumbers(nums);

    cout << "the result is: " << res[0] << " " << res[1] << endl;
    return 0;
}

// 时间复杂度: O(n)
// 空间复杂度: O(1)
