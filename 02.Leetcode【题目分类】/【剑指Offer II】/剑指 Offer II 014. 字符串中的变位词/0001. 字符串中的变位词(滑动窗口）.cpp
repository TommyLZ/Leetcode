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

        vector<int> cnt1(26), cnt2(26); // 统计字符的个数

        for (int i = 0; i < n; ++i) {
            ++cnt1[s1[i] - 'a']; // 统计s1对应字符的个数
            ++cnt2[s2[i] - 'a']; // 统计s2中窗口对应字符的个数
        }

        if (cnt1 == cnt2) { // 是变位词
            return true;
        }


        for (int i = n; i < m; ++i) { //

            ++cnt2[s2[i] - 'a']; // 窗口向前移动

            --cnt2[s2[i - n] - 'a']; // 从窗口退出一个元素

            if (cnt1 == cnt2) {
                return true;
            }
        }

        return false;
    }
};


int main() {
    Solution solution;

    string str1 = "ab", str2 = "eiifhoanab";

    bool res = solution.checkInclusion(str1, str2);

    cout << "the result is " << res << endl;

    return 0;
}

// 时间复杂度：O(n+m*∑): 进行数组之间的比较时间复杂度为O(∑)
// 空间复杂度: O(∑)
