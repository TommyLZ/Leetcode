#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ret = 0;

        for (int n : nums)
            ret ^= n;   // ����Ԫ�ص�����

        int div = 1;

        while ((div & ret) == 0)    // �ҵ����λ��1
            div <<= 1;

        int a = 0, b = 0;

        for (int n : nums)  // �������λ��1��λ�ý��з���
            if (div & n)
                a ^= n;
            else
                b ^= n;

        return vector<int>{a, b};
    }
};


int main() {
    Solution solution;
    vector<int> nums = {1, 2, 10, 4, 1, 4, 3, 3};

    vector<int> res = solution.singleNumbers(nums);

    cout << "the result is: " << res[0] << " " << res[1] << endl;
    return 0;
}

// ʱ�临�Ӷ�: O(n)
// �ռ临�Ӷ�: O(1)
