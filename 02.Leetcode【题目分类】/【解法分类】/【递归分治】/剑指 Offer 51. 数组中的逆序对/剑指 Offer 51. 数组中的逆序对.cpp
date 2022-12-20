// �鲢����
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
        if (l >= r) {
            return 0;
        }

        int mid = (l + r) / 2;

        // ����˼�룺�Ƚ�nums�������µݹ�ֽ�
        int inv_count = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);


        int i = l, j = mid + 1, pos = l;

        while (i <= mid && j <= r) {

            if (nums[i] <= nums[j]) {
                tmp[pos] = nums[i];
                ++i;
            }
            else {  // ��nums[i]>nums[j]ʱ�����ݹ鲢�����Ե����µ������ǰ�ᣬ��벿��ʣ��ĸ�������nums[j]��Ӧ������Եĸ���
                tmp[pos] = nums[j];
                ++j;
                inv_count += mid - i + 1;   // ���м���
            }

            ++pos;
        }

        // �Ұ벿�����ת�ƣ����ʣ����벿��
        for (int k = i; k <= mid; ++k) {
            tmp[pos++] = nums[k];
        }

        // ��벿�����ת�ƣ����ʣ���Ұ벿��
        for (int k = j; k <= r; ++k) {
            tmp[pos++] = nums[k];
        }


        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        // ���ź������һ�θ��ƽ���nums���У����Ե����Ͻ��кϲ���ʱ���ϲ�Ҫ���²㱣�����������Ǳ�֤ͳ����ȷ�Ե�ǰ��

        return inv_count;
    }


    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n);
        return mergeSort(nums, tmp, 0, n - 1);
    }
};


int main() {
    Solution solution;

    vector<int> nums = {7, 5, 6, 4};

    int res = solution.reversePairs(nums);

    cout << "the result is " << res << endl;

    return 0;
}
