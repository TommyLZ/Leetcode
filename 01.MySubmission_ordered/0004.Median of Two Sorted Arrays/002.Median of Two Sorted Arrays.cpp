#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) { // 确定小长度数组 
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int left = 0, right = m;

        int median1 = 0, median2 = 0;

        while (left <= right) { // 二分查找，找到符合条件的i
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;    //i和j之间存在的关系

            // nums_im1, nums_i, nums_jm1, nums_j 分别表示 nums1[i-1], nums1[i], nums2[j-1], nums2[j]
            int nums_im1 = (i == 0 ? INT_MIN : nums1[i-1]);
            int nums_i = (i == m ? INT_MAX : nums1[i]);
            int nums_jm1 = (j == 0 ? INT_MIN : nums2[j-1]);
            int nums_j = ( j == n ? INT_MAX : nums2[j]);

            if (nums_im1 <= nums_j) {
                median1 = max(nums_im1, nums_jm1);
                median2 = min(nums_i, nums_j);
                left = i + 1;
            }
            else {
                right = i - 1;
            }
        }


        return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : (median1);    // 直接在结果这里进行区分汇总, 过程当中不需要区分

    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double res = solution.findMedianSortedArrays(nums1, nums2);

    cout << "result: " << res << endl;
    return 0;
}