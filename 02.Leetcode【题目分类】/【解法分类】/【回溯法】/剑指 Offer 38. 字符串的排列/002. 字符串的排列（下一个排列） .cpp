//参照《下一个排列》解题所得

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool nextPermutation(string& s) {
        int i = s.size() - 2; 

        while (i >= 0 && s[i] >= s[i + 1]) { // 当前字符大于后一字符
            i--; // 左移
        }
        // 退出：当前字符小于后一字符 ([前面字符] [第i位字符M ] [以N开头的降序字符])

        if (i < 0) {    // s为降序字符串, 说明
            return false;
        }

        int j = s.size() - 1;
        while (j >= 0 && s[i] >= s[j]) {
            j--;
        }
        swap(s[i], s[j]);   // 将大数换到前面之后
        reverse(s.begin() + i + 1, s.end()); // 将后面的降序转换为升序
        return true;
    }

    vector<string> permutation(string s) {
        vector<string> ret;
        sort(s.begin(), s.end()); // 升序排列
        do {
            ret.push_back(s);
        } while (nextPermutation(s));
        return ret;
    }
};


int main() {
    Solution solution;

    string s = "abc";
    vector<string> rec = solution.permutation();

    for (string s: rec) {
        cout << s << endl;
    }

    return 0;
}

// 时间复杂度: O(n!)
// 空间复杂度：O(n)