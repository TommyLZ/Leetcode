#include <iostream>

using namespace std;

class Solution{
public:
    string reorderSpaces(string s) {
        int n = s.size();
        int space_cnt = n;
        int words_cnt = 0;
        // space_cnt: 统计空格字符的个数
        // words_cnt: 统计单词的个数
        
        // 该循环使单词与单词之间只有一个空格，其他的空格全部转移到了s的首部
        for (int i=n-1, j=n-1, space=false; i >=0; --i) { // 使得单词遍历结束时保留若干个空格，同时也辅助了单词个数的统计
        // 每次循环，i都向左移动一个单位
            if (s[i] != ' ') {   // 碰到非空格
                swap(s[i], s[j--]); // 当i==j时，实际上没有进行交换
                words_cnt += !space;    // 统计的是单词的个数
                space = true;  // 如果当前字符不是空格，刚好上一轮在此if分支，则当前轮进入else if分支
                --space_cnt;  // space_cnt的最终值统计空格字符的个数
            }
            else if (space) { // （保证单词与单词之间有一个空格存在）当前碰到当前字符是空格，而且上一次碰到的字符是非空格
                --j;    // 指针j向左移动一个空格， 这个时候指针j在指针i的左边，指针i指向的是空格
                // 这样做是在单词和单词之间保留了一个空格
                space = false;
            }
        }

        // cout << s << endl;

        // a = 空格字符个数/ （单词个数-1）
        // 需要用max(words_cnt-1, 1)比较大小，是为了考虑只有一个单词的情况
        for (int i=0, j=0, space = false, a = space_cnt / max(words_cnt-1, 1); i<n; ++i) {
        // 每一轮i向右移动一个单位
            if (s[i] != ' ') {  // 用来不断调整单词和空格的位置
                swap(s[i], s[j++]);
                space = true;
            }
            else if (space) { // i现在在移动过程中指向了单词与单词之间的空格，此时，j应该指向了刚刚完成调换的一个完整单词的最后一个字符的下一位
                j += a; // 这个时候j因该跳转到下一个新单词应该开始的位置，即j+a的位置
                space = false; // f设置成false，开始下一轮的替换
            }
        }

        return s;
    }
};

int main() {
    Solution solution;
    string s = "  this   is  a sentence ";
    string ans;

    ans = solution.reorderSpaces(s);

    cout << "answer:" << ans << endl;

    return 0;
}