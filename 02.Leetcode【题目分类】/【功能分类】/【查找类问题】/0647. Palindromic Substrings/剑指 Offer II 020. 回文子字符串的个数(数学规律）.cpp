#include <iostream>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;

        // 数学规律
        // 长度为n的字符串会生成2n-1组回文中心
        for (int i = 0; i < 2 * n - 1; ++i) { // i表示的是编号

            int l = i / 2, r = i / 2 + i % 2;

            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
                ++ans;
            }
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

// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
