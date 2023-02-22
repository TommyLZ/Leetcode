#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;

        // �ȼ���b�������µ�b����a�������˱��ʽ���Ż���
        for (int num: nums) {
            b = ~a & (b ^ num);
            a = ~b & (a ^ num);
        }

        return b;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 2, 3, 2};

    int res = solution.singleNumber(nums);

    cout << res << endl;

    return 0;
}

// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
