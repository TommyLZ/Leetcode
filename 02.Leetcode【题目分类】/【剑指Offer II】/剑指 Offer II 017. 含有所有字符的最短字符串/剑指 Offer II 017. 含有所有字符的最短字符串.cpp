#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map <char, int> ori, cnt;

    bool check() {
        for (const auto &p: ori) {
            if (cnt[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {

        for (const auto &c: t) {
            ++ori[c]; // 统计对应字符个数
        }

        int l = 0, r = -1; //

        int len = INT_MAX, ansL = -1, ansR = -1;
        cout << int(s.size()) << endl;
//        while (r < int(s.size())) { // 为什么这里要进行强制类型转换
          while (r < s.size()) {
            cout << "get in" << endl;
            if (ori.find(s[++r]) != ori.end()) {
                ++cnt[s[r]];
            }

            while (check() && l <= r) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ansL = l;
                }
                if (ori.find(s[l]) != ori.end()) {
                    --cnt[s[l]];
                }
                ++l;
            }
        }

        return ansL == -1 ? string() : s.substr(ansL, len);
    }
};


//
int main() {
    Solution solution;
    string s = "ADOBECODEBANC", t = "ABC", res ;

    res = solution.minWindow(s, t);

    cout << "the result is " << res << endl;
    return 0;
}
