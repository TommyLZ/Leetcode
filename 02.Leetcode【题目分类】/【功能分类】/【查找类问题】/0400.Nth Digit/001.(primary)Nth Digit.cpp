#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:

    int findNthDigit(int n) {
        int low = 1, high = 9;  // 确定n对应的数的位数的上下限（n最小在一位数中，n最大在9位数中）

        while (low < high) {    // 使用二分法确定n具体在几位数当中
            int mid = (high - low) / 2 + low;
            if (totalDigits(mid) < n) { // mid位数字及之前位数字之和小于n
                low = mid + 1;  // 更新下限
            } else {
                high = mid; // 更新上限
            }
        }

        int d = low;    // 最终low值存储的是n在low位数当中
        int prevDigits = totalDigits(d - 1);    // 算出之前d位数据之前的数位对应的数据的累加和
        int index = n - prevDigits - 1; // 从d位数开始定位，索引从0开始

        int start = (int) pow(10, d - 1);   // 开始进行数据定位和提取
        int num = start + index / d;    // 确定第n位数具体在哪个数当中
        int digitIndex = index % d;     // 确定第n位数具体是num中的第几位（第一位数，索引为0）
        int digit = (num / (int) (pow(10, d - digitIndex - 1))) % 10;   // 对num进行除法截断和取余，提取出第n位数
        return digit;
    }


    int totalDigits(int length) {   // 这里的数学规律很重要
        int digits = 0; 
        int curLength = 1, curCount = 9;

        while (curLength <= length) {
            digits += curLength * curCount;
            curLength++;    // 增加数位
            curCount *= 10; // 初值为9，累计乘10
        }

        return digits;  // 返回length位及之前位所有单个数据（一个数字一个数据）的累加个数
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