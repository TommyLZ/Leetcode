#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> sums; // �����Բ�����Ŀ�����ģ����Լ���Ϊ��ӵ�

    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums.resize(n + 1);

        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }

    }


    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);

    int res1 = numArray.sumRange(0, 2);
    int res2 = numArray.sumRange(2, 5);
    int res3 = numArray.sumRange(0, 5);

    cout << "the result1 is " << res1 << endl;
    cout << "the result2 is " << res2 << endl;
    cout << "the result3 is " << res3 << endl;

    return 0;
}

// ʱ�临�Ӷȣ�O(n)
// ������ʱ�临�Ӷ� == sumranage��ʱ�临�Ӷȣ�O(1)
   // �����ĺ�������main�����е���sumRange������������Ĵ���
   // ���ܻ���main�����е���sumRange����10^4�Σ���Ӧres1 ~ res10^4
   // �����б�Ҫ��sumRange��ʱ�临�Ӷ����ΪO(1)
// �ռ临�Ӷȣ�O(n)
