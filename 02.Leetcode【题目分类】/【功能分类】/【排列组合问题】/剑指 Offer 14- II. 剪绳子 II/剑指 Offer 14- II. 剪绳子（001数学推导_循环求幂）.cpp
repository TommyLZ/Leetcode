// 动态规划问题（数学过程：拆分成尽可能多的3）
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution{
public:
    int cuttingRope(int n) {
        if (n <= 3) {
            return n - 1;
        }

        int quotient = n / 3;
        int remainder = n % 3;
        const int mod = 1e9 + 7;
        long long int  mul = 1; // 这里必须是long long, 防止mul在乘以3的时候超出int类型

        for (int i = 1; i < quotient; ++i) {
            mul = mul * 3 % mod;
        }

        if (remainder == 0) {
            return mul * 3 % mod;
        }
        else if (remainder == 1) {
            // return mul / 3 * 4 % mod; // 使用求模之后的结果做除法，会出现错误
            return mul * 4 % mod;
        }
        else {
            return mul * 3 * 2 % mod;
        }   // 这里必须是else， 不能是else if，否则leetcode的编译器会报错
    }
};

int main()
{
    Solution solution;
    int n = 127;
    int res = solution.cuttingRope(n);

    cout << "the result is: " << res << endl;
    return 0;
}

//时间复杂度：O(n)
//空间复杂度：O(1)
