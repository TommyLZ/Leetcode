#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;

        while (left < right) {
            // 筛选
            while (left < right && !isalnum(s[left])) {
                ++left;
            }

            while (left < right && !isalnum(s[right])) {
                --right;
            }

            // 筛选完成之后
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                ++left;
                --right;
            }
        }
        return true;
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
// 空间复杂度：O(1)
