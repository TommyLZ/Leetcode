#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution{
public:
    int minSubArrayLen(int target, vector<int>& nums){
        int n = nums.size();
        int start = 0, end = 0;
        int sum = 0;
        int ans = INT_MAX;

        if (n == 0){
            return 0;
        }

        while (end < n){
            sum += nums[end];

            while (sum >= target){
                ans = min(ans, end - start + 1);
                sum -= nums[start++]; 
            }

            end++;
        }

        return (ans == INT_MAX)? 0 : ans;
    }
};

int main(){
    Solution solution;
    int target = 7;
    vector<int> nums {2,3,1,2,4,3};
    int ans;

    ans = solution.minSubArrayLen(target, nums);

    cout << "ans: " << ans << endl;

    return 0;
}
