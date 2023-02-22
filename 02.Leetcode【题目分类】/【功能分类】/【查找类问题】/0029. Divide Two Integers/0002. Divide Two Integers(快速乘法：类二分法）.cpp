// 快速乘
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int divide(int a, int b) {
        // 考虑被除数为最小值的情况
        if (a == INT_MIN) {
            if (b == 1) {
                return INT_MIN;
            }
            if (b == -1) {
                return INT_MAX;
            }
        }
        // 考虑除数为最小值的情况
        if (b == INT_MIN) {
            return a == INT_MIN ? 1 : 0;
        }
        // 考虑被除数为 0 的情况
        if (a == 0) {
            return 0;
        }

        // 一般情况，使用类二分查找
        // 将所有的正数取相反数，这样就只需要考虑一种情况
        bool rev = false;
        if (a > 0) {
            a = -a;
            rev = !rev;
        }
        if (b > 0) {
            b = -b;
            rev = !rev;
        }


        vector<int> candidates = {b};

        // 注意溢出
        while (candidates.back() >= a - candidates.back()) {
            candidates.push_back(candidates.back() + candidates.back());
        }

        int ans = 0;

        // 实际上这里是在构造商的二进制表示形式
        // 实际上这里进行的是二分查找（不断变更left和right的范围）
        for (int i = candidates.size() - 1; i >= 0; --i) {

            if (candidates[i] >= a) {
                ans += (1 << i); // 乘以2的i次方
                a -= candidates[i];
            }

        }

        return rev ? -ans : ans;
    }
};


int main() {
    Solution solution;

    int a = 15, b = 2;

    int res = solution.divide(a, b);

    cout << "the result is: " << res << endl;

    return 0;
}

// 时间复杂度：O(logC): C表示32位整数的范围
// 空间复杂度：O(1)
