#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    double findMaxAverage(vector<int>& nums, int k){
        double ans = 0;
        int i = 0;
        double sum = 0;

        for( int j=0; j<k; ++j){
            ans += nums[j];
        }

        sum = ans;

        for(int j=k; j<nums.size(); ++j){
            sum = sum - nums[i++] + nums[j];
            ans = max(ans, sum);
        }

        return ans/k;
    }
};


int main(){
    Solution solution;
    vector<int> nums {1,12,-5,-6,50,3};
    int k = 4;
    double ans = 0;

    ans = solution.findMaxAverage(nums, k);

    cout << "ans: " << ans << endl;

    return 0;
}