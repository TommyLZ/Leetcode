// ����ʱ������

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;

        for (int start = 0; start < nums.size(); ++start) {

            int sum = 0;

            for (int end = start; end >= 0; --end) {
                sum += nums[end];
                if (sum == k) {
                    count++;
                }
            }
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

// ʱ�临�Ӷȣ� O(n^2)
// �ռ临�Ӷȣ�O(1)
