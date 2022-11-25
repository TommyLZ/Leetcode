#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int expand (const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            -- left;
            ++ right;
        }

        return (right - left - 2) / 2; // 这里计算的是臂的长度，所以是减2，不是减1
    }


    string LongestPalindrome(string s) {
        int start = 0, end = -1;

        // 统一字符串的奇偶
        string t = "#";
        for (char c: s) {
            t += c;
            t += "#";
        }
        
        t += "#";
        s = t;

        vector<int> arm_len;
        int right = -1, j = -1; // right表示的是j+(j的臂)的结果，定义j从-1开始，j的臂为0，所以right的值为-1
        for (int i = 0; i < s.size(); ++i) { // 从0号下标元素为中心进行拓展
            int cur_arm_len;
            if (right >= i) {   // 满足下面步骤的执行条件是，当前i需要在right以内，才能计算跳过的值
                int i_sym = j * 2 - i; // 找到i关于j的对称点的下标
                int min_arm_len = min(arm_len[i_sym], right - i);   // 找到最小值
                cur_arm_len = expand(s, i - min_arm_len, i + min_arm_len);  // 跳过重复计算进行拓展
            }
            else {  // 当前i没有在j的臂的范围内的话，就只能从单个字符开始拓展
                cur_arm_len = expand(s, i, i);  // 从单个字符开始拓展
            }

            arm_len.push_back(cur_arm_len); // 保存记录（当前i位置拓展完毕）

            if (i + cur_arm_len > right) {
                j = i;  // 为什么要跟新j的值？ 不更新，新的循环中的i值可能会超过right,即使本应该能通过改算法跳过重复的计算，但是因为j没有更新，所以只能选择作为单个字符向两边拓展的方式
                right = i + cur_arm_len; 
            } 
            // 当前的i，加上i的臂，能覆盖的范围比当前的right更广，所以自然而然，会对j和right做这样的更新

            if (cur_arm_len * 2 + 1 > end -start) { // 长度更新
                start = i- cur_arm_len;
                end = i + cur_arm_len;
            }
        }
        
        string ans; // 截取最长回文子串
        for (int i = start; i <= end; ++i) {
            if (s[i] != '#') {
                ans += s[i];
            }
        }

        return ans;
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