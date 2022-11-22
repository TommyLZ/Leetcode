// 中心扩展算法
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    pair<int, int> expandAroundCenter (const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {  // 从中心向两边拓展
            -- left;
            ++ right;
        }
        return {left + 1, right - 1};   // 将拓展得到的回文字符串的范围返回
    }

    string LongestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto [left1, right1] = expandAroundCenter(s, i, i); // 从一个字符开始向两边拓展
            auto [left2, right2] = expandAroundCenter(s, i, i + 1); // 从两个字符开始向两边拓展
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};

int main () {
    Solution solution;

    // string s = "babad";
    string s = "cbbd";

    string res = solution.LongestPalindrome(s);

    cout << "result: " << res << endl;
    return 0;
}