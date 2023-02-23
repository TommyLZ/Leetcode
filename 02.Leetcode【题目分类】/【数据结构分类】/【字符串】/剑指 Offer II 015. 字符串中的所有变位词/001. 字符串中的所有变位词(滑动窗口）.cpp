#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();

        if (sLen < pLen) {
            return vector<int>();
        }

        vector<int> ans;
        vector<int> sCount(26);
        vector<int> pCount(26);

        for (int i = 0; i < pLen; ++i) {
            ++sCount[s[i] - 'a'];
            ++pCount[p[i] - 'a'];
        }

        if (sCount == pCount) { // 初始状态下就相等，将索引0添加在数组当中
            ans.emplace_back(0);
        }

        // 在长字符串上进行滑动
        // 长字符串上最后不满足短字符串长度的部分可以不检查，因为一定不满足题目要求
        for (int i = 0; i < sLen - pLen; ++i) {

            // 窗口丢弃
            --sCount[s[i] - 'a'];

            // 窗口纳入
            ++sCount[s[i + pLen] - 'a'];

            if (sCount == pCount) {
                ans.emplace_back(i + 1);
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string s = "cbaebabacd", p = "abc";

    vector<int> res = solution.findAnagrams(s, p);

    for (int i: res) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}

// 时间复杂度：O(m+(n-m)∗∑)-->两个数组的比较需要用∑时间
// 空间复杂度：O(∑)
