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
        vector<int> count(26);

        for (int i = 0; i < pLen; ++i) {
            ++count[s[i] - 'a'];
            --count[p[i] - 'a'];
        }

        int differ = 0;

        for (int j = 0; j < 26; ++j) {
            if (count[j] != 0) {
                ++differ;
            }
        }

        if (differ == 0) {
            ans.emplace_back(0);
        }

        for (int i = 0; i < sLen - pLen; ++i) {

            // 窗口舍弃, 舍弃之前cnt值为1,说明窗口多了
            // 舍弃之后，减少差异，所以需要进行diff减减操作
            if (count[s[i] - 'a'] == 1) {  // 窗口中字母 s[i] 的数量与字符串 p 中的数量从不同变得相同
                --differ;
            } else if (count[s[i] - 'a'] == 0) {  // 窗口中字母 s[i] 的数量与字符串 p 中的数量从相同变得不同
                ++differ;
            }
            --count[s[i] - 'a']; // 对s来说，舍弃一个就是减法


            // 窗口纳入
            // 纳入之前为-1，说明少了，纳入之后减少差异，所以--diff
            if (count[s[i + pLen] - 'a'] == -1) {  // 窗口中字母 s[i+pLen] 的数量与字符串 p 中的数量从不同变得相同
                --differ;
            } else if (count[s[i + pLen] - 'a'] == 0) {  // 窗口中字母 s[i+pLen] 的数量与字符串 p 中的数量从相同变得不同
                ++differ;
            }

            ++count[s[i + pLen] - 'a'];

            if (differ == 0) {
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

// 时间复杂度：O(n+m+∑)-->两个数组的比较需要用∑时间
// 空间复杂度：O(∑)
