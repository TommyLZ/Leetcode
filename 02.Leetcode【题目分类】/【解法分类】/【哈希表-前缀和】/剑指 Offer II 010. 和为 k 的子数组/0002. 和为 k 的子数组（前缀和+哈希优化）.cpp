#include <iostream>
#include <vector>
using namespace std;


// 自己写一个数组，然后按照程序走一遍就能理解
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1; // 也是需要计数的

        int count = 0, pre = 0;

        // 题目：整数数组，数组当中可能存在负数
        for (auto& x:nums) {
            pre += x; // 累加和

            // 找到距离k的存储在哈希表中的累加和
            if (mp.find(pre - k) != mp.end()) {

                count += mp[pre - k];
                // 但是这里会统计重复吗？（经过验证，不会统计重复）
                // 数学原理：pre-k这个值出现过多少次，就说明从对应位置到现在的pre有几个连续的数组
            }

            mp[pre]++; // 同一个pre可能由多种情况得出，统计pre在整个累加过程中出现的次数
        }
        return count;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {1,1,1};
    int k = 2, res;

    res = solution.subarraySum(nums, k);

    cout << " the result is " << res << endl;

    return 0;
}

// 时间复杂度：O(n)
// 空间复杂度：O(n)
