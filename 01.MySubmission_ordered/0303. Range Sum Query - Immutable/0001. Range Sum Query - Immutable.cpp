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

    // 多次检索，多次调用sumrange

    // 原因：sumRange只给了两个参数
    // 如果不自己定义一个sum数组存储前缀和，则只能在main函数中多次通过对象调用sumRange函数
    // 多次调用sumrange函数就是多次进行检索
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
