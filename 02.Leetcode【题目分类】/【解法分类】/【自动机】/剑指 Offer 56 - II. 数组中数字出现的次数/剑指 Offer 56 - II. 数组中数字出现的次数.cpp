#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums){
        int ones = 0, twos = 0;
        for(int num : nums){
            ones = ones ^ num & ~twos;
            twos = twos ^ num & ~ones;
        }
        return ones;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {9,1,7,9,7,9,7};

    int res = solution.singleNumber(nums);

    cout << "the result is: " << res << endl;
    return 0;
}

// 时间复杂度: O(N)
// 空间复杂度: O(1)
