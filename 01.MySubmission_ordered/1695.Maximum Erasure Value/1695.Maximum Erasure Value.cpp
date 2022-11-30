#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maximumUniqueSubarray(vector<int>& nums){
        vector<bool> visit (10001);
        int ans = 0;
        int start = 0;
        int sum = 0;

        for(int end=0; end<nums.size(); ++end){
            while(visit[nums[end]]){
                sum -= nums[start];
                visit[nums[start++]] = false;
            }

            sum += nums[end];
            visit[nums[end]] = true;

            ans = max(ans, sum);
        }
        return ans;
    }
};

int main(){
    Solution solution;
    vector<int> nums {4,2,4,5,6};
    int ans = 0;

    ans = solution.maximumUniqueSubarray(nums);

    cout << "ans: " << ans << endl;
    return 0;
}