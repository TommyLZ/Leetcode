#include <iostream>
#include <cmath>

using namespace std;

class Solution{
public:
    int findNthDigit(int n) {
        int d = 1, count = 9;   // 从1开始，表示d位数有9个

        while ( n > (long) d * count) { // 这里为什么用long
            n -= d * count; // n不断减少是为了确定，n到底是在几位数当中
            d++;    //位数增加
            count *= 10;    //d位数的个数增加十倍
        }

        int index = n-1;    // (这里的n已经是将其他位排除的剩余数了）index即为目标数字在所有d位数中的下标，index的最小可能取值是0
        int start = (int) pow(10, d-1);   // 从d位数的第一个数字开始
        int num = start + index / d;    // 该运算确定第n个数在从start开始第几个数内， 这个数的数值就是num
        int digitIndex = index % d; // 该元素确定第n个数是在num中从左向右数的第几位（索引从0开始）
        int digit = (num / (int) (pow(10, d - digitIndex - 1)) ) % 10;
        // 公式理解：幂是为了截断——确定了第n个数是在num中从左向右数的第digitIndex位，那么对应的，第n个数就是在从右向左数的第d-digitIndex-1位
        // 为了提取出最终的值，用除法做截断，再进行取余运算，方能提取出第n位数

        return digit;
    }
};

int main() {
    Solution solution;
    int n = 11;
    int ans;

    ans = solution.findNthDigit(n);

    cout << "answer: " << ans << endl;
    return 0;
}