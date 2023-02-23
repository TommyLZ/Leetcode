#include <iostream>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLength = 0;
        unordered_map<int, int> mp;

        int counter = 0;
        // 存储新数组的前缀和： 当遇到元素1时将counter的值加1，当遇到元素0时将counter的值减1
        // 遍历过程中使用哈希表存储每个前缀和第一次出现的下标

        mp[counter] = -1; // 初始化

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int num = nums[i];

            if (num == 1) {
                counter++;
            } else {
                counter--;
            }

            // 在哈希表中存在： 说明该counter之前遇到过，进而说明再次碰到和第一次碰到之间的和为0--> 说明此段0和1的个数是相等的
            if (mp.count(counter)) {
                int prevIndex = mp[counter]; // 取出第一次碰到该counter的索引

                maxLength = max(maxLength, i - prevIndex); // 进行长度比较
            } else {

                mp[counter] = i; // 保存第一次碰到的索引
            }
        }

        return maxLength;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 1, 1};
    int k = 2, res;

    res = solution.findMaxLength(nums, k);

    cout << "the result is " << res << endl;

    return 0;
}

// 时间复杂度：O(n)
// 空间复杂度: O(n)
