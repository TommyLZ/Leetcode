#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 将元素按照从小到大进行排序
        int last_elem = 0;  // j从0开始累加尝试
        
        for (int i=0; i<nums.size(); ++i) { // 数组中的每个元素对j而言都是一个认证点
            int remain_num = nums.size() - i;

            for(int j=last_elem; j<=nums[i]; ++j) { // j从last_elem开始进行累加
                if (remain_num < j) {   // 剩余元素个数小于j, 说明找不到符合题意的x值
                    return -1;
                }
                else if (remain_num == j) { // 剩余元素个数等于j, 当前的j值即为题目要求的值
                    return j;
                }
            }

            last_elem = nums[i] + 1;    // j一直尝试到nums[i], 都没有找到符合条件的x，所以，下一轮从新的值nums[i]+1开始
        }

        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums =  {0, 4, 3, 0, 4};

    int ans = solution.specialArray(nums);

    cout << "answer: " << ans << endl;

    return 0;
}