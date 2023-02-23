#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};


int main(){
    Solution solution;
    vector<int> nums = {3, 2, 3};
    vector<int> ans;
    int target = 6;

    ans = solution.twoSum(nums, target);

    cout << "ans: [";

    for (int i=0; i<ans.size(); ++i){
        if (i == ans.size() - 1){
            cout << ans[i];
            break;
        }
        cout << ans[i] << ",";
    }
    
    cout << "]";

    return 0;
}