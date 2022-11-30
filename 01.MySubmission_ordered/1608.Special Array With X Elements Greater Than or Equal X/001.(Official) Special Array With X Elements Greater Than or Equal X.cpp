#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {

        sort(nums.begin(), nums.end(), greater<int>()); // 降序排列

        int n = nums.size();

        for (int i = 1; i <= n; ++i) {  // 特征值一定在1~n之间,只需要遍历0~1
            if (nums[i - 1] >= i && (i == n || nums[i] < i)) {  // i值一定满足在nums[i-1]到nums[i]之间， 由于是降序排列，所以nums[i-1]值更大
                return i;
            }
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