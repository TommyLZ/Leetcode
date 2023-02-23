#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();

        if (n > m) {
            return false;
        }

        vector<int> cnt(26);

        for (int i = 0; i < n; ++i) {
            --cnt[s1[i] - 'a'];
            ++cnt[s2[i] - 'a'];
        }

        int diff = 0; // 使用diff来记录cnt1和cnt2的不同值的个数
        // 转换：为了避免每次将两个标记数组进行比较，转换成了判断diff是否为0

        for (int c: cnt) {
            if (c != 0) {
                ++diff; // 统计不同字符的个数
            }
        }

        if (diff == 0) {
            return true;
        }

        for (int i = n; i < m; ++i) {

            int x = s2[i] - 'a', y = s2[i - n] - 'a'; // 两个之间刚好隔了n个

            // x是窗口准备新纳入的，y是窗口准备新舍弃的

            if (x == y) {   // 相等的话，对cnt的计算并不会有什么影响
                continue;
            }

            // 新纳入x之前，cnt[x]值为0，说明s1和在s2的窗口中，x的值是相等的
            // 现在窗口新纳入了x，舍弃了y, 同时，程序能够执行到这一步，说明x 不等于 y
            // 所以，现在窗口比s1多了1个x, 需要执行diff++
            if (cnt[x] == 0) {
                ++diff;
            }

            ++cnt[x]; // 现在正式将x 纳入窗口

            // 将x正式纳入窗口之后，窗口和s1的x达到平衡
            // 说明窗口和s1的差异减小，因此执行diff--
            if (cnt[x] == 0) {
                --diff;
            }

            // 同理，在舍弃y之前是平衡的
            // 现在正式舍弃了y, 说明窗口比s1少了一个y, 差异增加了
            if (cnt[y] == 0) {
                ++diff;
            }

            --cnt[y]; // 现在正式从窗口舍弃y


            // 正式舍弃y之后，达到了平衡，差异减小
            if (cnt[y] == 0) {
                --diff;
            }


            // 每次窗口移动，都需要判断
            if (diff == 0) {
                return true;
            }
        }

        return false; // 遍历s2结束的整个过程都没有return ture, 就说明不是，直接返回
    }
};


int main() {
    Solution solution;

    string str1 = "ab", str2 = "eiifhoanab";

    bool res = solution.checkInclusion(str1, str2);

    cout << "the result is " << res << endl;

    return 0;
}

// 时间复杂度：O(n+m+∑)
// 空间复杂度: O(∑)
