// 归并排序
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

        // 分治思想：先将nums不断向下递归分解
        int inv_count = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);


        int i = l, j = mid + 1, pos = l;

        while (i <= mid && j <= r) {

            if (nums[i] <= nums[j]) {
                tmp[pos] = nums[i];
                ++i;
            }
            else {  // 当nums[i]>nums[j]时，根据归并排序自底向下的有序的前提，左半部分剩余的个数就是nums[j]对应的逆序对的个数
                tmp[pos] = nums[j];
                ++j;
                inv_count += mid - i + 1;   // 进行计数
            }

            ++pos;
        }

        // 右半部分完成转移，完成剩余左半部分
        for (int k = i; k <= mid; ++k) {
            tmp[pos++] = nums[k];
        }

        // 左半部分完成转移，完成剩余右半部分
        for (int k = j; k <= r; ++k) {
            tmp[pos++] = nums[k];
        }


        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        // 将排好序的这一段复制进入nums当中，再自底向上进行合并的时候，上层要求下层保持升序，升序是保证统计正确性的前提

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
