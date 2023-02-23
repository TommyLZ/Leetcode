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
            --cnt[s1[i] - 'a'];     // 反向统计
        }

        int left = 0;

        // 解题思路：在保证cnt不正的情况下，去考察是否存在一个区间，其长度恰好是n
        for (int right = 0; right < m; ++right) {
        // right一直在向前移动

            int x = s2[right] - 'a'; // 当前字符
            ++cnt[x]; // 将当前字符划入双指针的范围内

            // 但是这个和cnt有什么必要联系吗？
            // 当right指向的元素对应的cnt小于0等于0时，说明和s1是有对应的
            // 当right指向的元素对应的cnt大于0时，说明和s1相比，出现了多余的字母（不管是种类还是数量上）
            // 也就是说right指向的元素并不在考虑的范围内
            // 由于right随着循环一直在不断向右移动，所以为了将这个不在范围内的数排除在外
            // left也得执行++操作，同时，left指向的元素被排除在了范围之外，对应的cnt需要执行--
            while (cnt[x] > 0) { // 说明指针范围内x太多了,
                --cnt[s2[left] - 'a']; // 减少离开字符的区间的cnt
                ++left; // 左指针右移
            }

            // 当随着left的移动，将cnt[x]降低到0的时候，检查双指针之间的距离
            if (right - left + 1 == n) { // 双指针区间长度刚好为n时，找到子串
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

// 时间复杂度：O(n+m+∑) --> 创建cnt需要O(∑)时间
// 空间复杂度: O(∑)
