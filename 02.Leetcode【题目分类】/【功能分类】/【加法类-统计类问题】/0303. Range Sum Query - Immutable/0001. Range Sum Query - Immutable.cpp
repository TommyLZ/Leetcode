#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> sums; // 该属性不是题目给定的，是自己人为添加的

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

// 时间复杂度：O(n)
// 检索的时间复杂度 == sumranage的时间复杂度：O(1)
   // 检索的含义是在main函数中调用sumRange函数的做运算的次数
   // 可能会在main函数中调用sumRange函数10^4次，对应res1 ~ res10^4
   // 所以有必要将sumRange的时间复杂度设计为O(1)
// 空间复杂度：O(n)
