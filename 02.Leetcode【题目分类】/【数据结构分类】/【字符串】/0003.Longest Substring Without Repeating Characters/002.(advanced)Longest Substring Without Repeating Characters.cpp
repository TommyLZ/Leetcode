#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> occ;

        int n = s.size();
        int j = -1;
        int ans = 0;

        for(int i=0; i<n; ++i) {    // 左指针向右移动
            if (i!=0) { // 左指针之前的数据全部删除
                occ.erase(s[i-1]);
            }

            while (j+1<n && !occ.count(s[j+1])) {   // 不越界,不重复
                occ.insert(s[j+1]);
                ++j;
            }

            //  退出循环,说明遇到了重复值
            ans = max(ans, j-i+1);
        }

        return ans;
    }
};

int main(){
    Solution solution;

    string s = "abcabcbb";
    int ans = 0;

    ans = solution.lengthOfLongestSubstring(s);

    cout << "answer:" << ans << endl;

    return 0;
}