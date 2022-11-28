#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        // string s = x; 错误写法
        if (x < 0)
            return false;
        string s= "";
        while (x) {
            s += x % 10;
            x /= 10;
        }

        int left = 0, right = s.size() - 1;

        while (left <= right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }

        return true;
    }
};

int main () {
    Solution solution;
    
    // int x = 121;
    int x = -1221;

    bool res = solution.isPalindrome(x);

    cout << "the result is: " << res << endl;
    return 0;
}

//时间复杂度： O(n)
//空间复杂度： O(n)