#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;

        int e = 0;
        for (int num: nums) {

              // 使用tie函数的作用是：实现pair的对应赋值
              // 并且使用pair能够实现a和b的同步计算
              tie(a, b) = pair{(~a & b & num) | (a & ~b & ~num), ~a & (b ^ num)};


              // 注意：上式不可以替换成：
              // a = (~a & b & num) | (a & ~b & ~num);
              // b = ~a & (b ^ num);
              // 因为a和b必须要同时进行计算


              // 不能使用c++ 17的auto结构化绑定，因为 auto之后定义的c和f要求是第一次定义
              // 上面等式的要求就是等式两边都有a,b和auto的使用要求是互相冲突的
              // 下面的式子并不是本题的正确表达是，所以也不能正确解出本题
              // auto [c, f] = pair{(~a & b & num) | (a & ~b & ~num), ~a & (b ^ num)};
              // e = f;
        }

        // return e;

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

// 时间复杂度：O(n)
// 空间复杂度：O(1)
