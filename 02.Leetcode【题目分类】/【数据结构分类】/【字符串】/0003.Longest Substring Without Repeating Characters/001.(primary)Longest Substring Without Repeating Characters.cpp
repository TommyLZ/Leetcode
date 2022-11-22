#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s){
        vector<int> place (128, 0); // 建立索引数组
        int i = 0;  // 滑动窗口左指针
        int ans = -1;

        for (int j=0; j<s.size(); ++j){ // 窗口右指针滑动

            i = max(i, place[s[j]]);    // 当前字符为s[j], place[s[j]]是上个相同字符s[j]的下一个位置
                                        // 该位置在i左边，则i~j之间没有重复字符
                                        // 该位置在i右边，说明i~j之间有重复字符，左指针i必须跳转到对应的place[s[j]]
            place[s[j]] = j+1;  // 重复的时候，i应该移动到j+1的位置
            ans = max(ans, j-i+1);  // 结果不断取最大值
        }

        return ans;
    }
};

int main(){
    Solution solution;
    string s = "abcabcbb";
    int ans = 0;

    ans = solution.lengthOfLongestSubstring(s);
    
    cout << "ans: " << ans << endl;

    return 0;
}