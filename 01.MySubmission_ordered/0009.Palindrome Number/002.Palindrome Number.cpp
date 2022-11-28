// 反转思路
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || ( x % 10 == 0 && x != 0)) // 排除负数和末尾为0的数
            return false;
        
        int revertedNumber = 0; // 存储后半部分翻转结果

        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        return x == revertedNumber || x == revertedNumber / 10;
    }
};

int main () {
    Solution solution;
    
    // int x = 121;
    int x = 1221;

    bool res = solution.isPalindrome(x);

    cout << "the result is: " << res << endl;
    return 0;
}

//时间复杂度： O(logn)
//空间复杂度： O(1)