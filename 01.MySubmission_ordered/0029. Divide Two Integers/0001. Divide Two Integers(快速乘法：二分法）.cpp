// 快速乘
#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int a, int b) {

        // 考虑被除数a为最小值的情况
        if (a == INT_MIN) {
            if (b == 1) {
                return INT_MIN;
            }
            if (b == -1) {
                return INT_MAX; // 返回整数最大值，防止溢出
            }
        }

        // 考虑除数b为最小值的情况
        if (b == INT_MIN) {
            return a == INT_MIN ? 1 : 0;
        }

        // 考虑被除数为 0 的情况
        if (a == 0) {
            return 0;
        }


        //************************************************************************
        // 一般情况，使用二分查找

        // 将所有的正数取相反数，这样就只需要考虑一种情况
        bool rev = false;

        // 将正数变成负数的优点是防止溢出：结果符号的事情可以最后考虑
        if (a > 0) {
            a = -a;
            rev = !rev;
        }

        if (b > 0) {
            b = -b;
            rev = !rev;
        }

        //************************************************************************
        // 快速乘
        auto quickAdd = [](int y, int z, int x) { // 匿名函数
            // x 和 y 是负数，z 是正数
            // 需要判断 z * y >= x 是否成立（针对两个负数的乘法，这个条件一定是成立的）

            int result = 0, add = y; // y是一个负数

            // 寻找x/y的结果，因为x和y都是负数，所以结果一定是正数或者0
            // 这个循环就是快速乘的循环I（相当于计算z*y): 原理和快速幂是相同的
            while (z) {

                if (z & 1) { // z是奇数
                    // 需要保证 result + add >= x （题解有说明原因）
                    // z是一个正数，y是一个负数，x是一个负数（且是最小的负数），z*y >= x
                    // 所以，在找到最大的z之前，z*y 永远是比z要大的（转换成快速乘（通过加法实现），累加值是永远大于等于x的）
                    // 换成下面的写法是为了防止溢出
                    if (result < x - add) {
                        return false;  // z一定不是x/y的商
                    }
                    result += add; // 累加y值
                }

                // 最终都会落到 z >> 2 == 1上，然后通过上个if语句将结果累加到result上（整个快速乘到此结束）
                // 所以：下面的if语句为快速乘的一般情况，z >> 2 ==1的时候是不需要做这一步的
                if (z != 1) {
                    // 需要保证 add + add >= x，使用加法的形式是为了防止溢出
                    if (add < x - add) {
                        return false; // z一定不是x/y的商
                    }
                    add += add;
                }

                // 不能使用除法：采用右移一位的方法
                z >>= 1;
            }

            return true;
        };


        //***********************************************************************
        int left = 1, right = INT_MAX, ans = 0;


        // 二分查找（必须是要查找到最大值）
        while (left <= right) {

            // 注意溢出，并且不能使用除法
            int mid = left + ((right - left) >> 1);

            bool check = quickAdd(b, mid, a); // 快速乘法（判断mid是否是a/b的商

            if (check) { // 如果mid可能为商
                ans = mid;

                // 注意溢出
                // 极端情况：当 mid == INT_MAX, 且check为true的时候
                // 再执行下面的left = mid + 1, 会发生溢出，所以这个时候需要break,（商z已经是最大了，也不能具体再往下找了）
                if (mid == INT_MAX) {
                    break;
                }

                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return rev ? -ans : ans; // 是否是一正一负？ 是（结果是负数）：否（结果是正数）
    }
};


int main() {
    Solution solution;

    int a = 15, b = 2;

    int res = solution.divide(a, b);

    cout << "the result is: " << res << endl;

    return 0;
}

// 时间复杂度：O(logC^2): C表示32位整数的范围
// 空间复杂度：O(1)
