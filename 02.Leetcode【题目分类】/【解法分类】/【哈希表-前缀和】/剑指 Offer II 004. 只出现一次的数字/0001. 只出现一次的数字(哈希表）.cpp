#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int, int> freq;

        for (int num: nums) { // 初始化哈希表
            ++freq[num];
        }

        int ans = 0;

        // c++ 17 结构化绑定
        for (auto [num, occ]: freq) { // 遍历
            if (occ == 1) {
                ans = num;
                break;
            }
        }

        return ans;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {2, 2, 3, 2};

    int res = solution.singleNumber(nums);

    cout << res << endl;

    return 0;
}
