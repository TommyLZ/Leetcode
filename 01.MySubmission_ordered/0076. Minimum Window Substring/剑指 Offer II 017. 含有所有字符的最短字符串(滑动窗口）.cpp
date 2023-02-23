#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map <char, int> ori, cnt;

    bool check() {

        // 对字符种类数组进行遍历
        for (const auto &p: ori) {

            // 当前在长字符串上的遍历范围在数量书并不满足ori中的统计条件
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

        int l = 0, r = -1;

        int len = INT_MAX, ansL = -1;

        // 注意：s.size()的返回值size_t是无符号的整数
        // r的初值为-1, 最高符号位为1
        // 有符号数和无符号数比较大小：会将有符号数直接当作无符号数进行比较

        // 所以，为了能够进行正常的比较，必须将无符号数转换成有符号数

        // 为了避免此类bug
        // 不用此写法：while (r < int(s.size())) {
        int n = s.size();
        while (r < n){

            // 找到匹配的字符
            if (ori.find(s[++r]) != ori.end()) {
                ++cnt[s[r]]; // 统计个数
            }

            while (l <= r && check()) {
            // 如果在字符数量上满足了要求
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ansL = l; //
                }

            // 移动左指针，开始做范围缩减
                if (ori.find(s[l]) != ori.end()) {
                    --cnt[s[l]];
                }

                ++l;
            }
        }

        return ansL == -1 ? string() : s.substr(ansL, len);
    }
};


int main() {
    Solution solution;
    string s = "ADOBECODEBANC", t = "ABC", res ;

    res = solution.minWindow(s, t);

    cout << "the result is " << res << endl;
    return 0;
}
