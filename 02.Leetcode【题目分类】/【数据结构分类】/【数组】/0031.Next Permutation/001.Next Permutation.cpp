#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main () {
    Solution solution;
    vector<int> nums = {1, 2, 3};

    solution.nextPermutation(nums);

    for (int num: nums) {
        cout << num << endl;
    }
    return 0;
}