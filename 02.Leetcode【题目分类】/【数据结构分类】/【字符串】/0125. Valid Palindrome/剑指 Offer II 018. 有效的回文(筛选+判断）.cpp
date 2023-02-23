#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;

        for (char ch: s) {

            // 内置函数：检查所传的符号是否是数字或者字母
            if (isalnum(ch)) {
                sgood += tolower(ch); // 进行大小写转换
            }
        }

        string sgood_rev(sgood.rbegin(), sgood.rend());

        return sgood == sgood_rev;
    }
};

int main() {
    Solution solution;
    string  s =  "A man, a plan, a canal: Panama";

    bool res = solution.isPalindrome(s);

    cout << "the result is " << res << endl;

    return 0;
}

// 时间复杂度：O(|s|)
// 空间复杂度：O(|s|)
