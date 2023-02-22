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

    // ��μ�������ε���sumrange

    // ԭ��sumRangeֻ������������
    // ������Լ�����һ��sum����洢ǰ׺�ͣ���ֻ����main�����ж��ͨ���������sumRange����
    // ��ε���sumrange�������Ƕ�ν��м���
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
