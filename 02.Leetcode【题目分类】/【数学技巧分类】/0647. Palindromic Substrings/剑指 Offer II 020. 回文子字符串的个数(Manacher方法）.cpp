#include <iostream>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        string t = "$#";

        // 统一奇偶的情况： 使用#隔开所有的字母，同时首位添加#
        for (const char &c: s) {
            t += c;
            t += '#';
        }

        n = t.size();
        t += '!';

        auto f = vector <int> (n);
        int iMax = 0, rMax = 0, ans = 0; // 左指针，右指针

        // 结合解析，画图即可理解
        // 遍历新修改的字符串
        for (int i = 1; i < n; ++i) {

            // 初始化 f[i]
            f[i] = (i <= rMax) ? min(rMax - i + 1, f[2 * iMax - i]) : 1;

            // 中心拓展 （从中心向两边进行扩展）
            while (t[i + f[i]] == t[i - f[i]])
                ++f[i];

            // 动态维护 iMax 和 rMax
            if (i + f[i] - 1 > rMax) {
                iMax = i;
                rMax = i + f[i] - 1;
            }

            // 统计答案, 当前贡献为 (f[i] - 1) / 2 上取整
            ans += (f[i] / 2);
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string s = "abc";

    int res = solution.countSubstrings(s);

    cout << "the result is " << res << endl;

    return 0;
}


// 时间复杂度：O(n)
// 空间复杂度：O(n)
